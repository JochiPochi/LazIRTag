/*
 * IRremote
 * Version 0.11 August, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
 *
 * Modified by Paul Stoffregen <paul@pjrc.com> to support other boards and timers
 * Modified  by Mitra Ardron <mitra@mitra.biz> 
 * Added Sanyo and Mitsubishi controllers
 * Modified Sony to spot the repeat codes that some Sony's send
 *
 * Interrupt code based on NECIRrcv by Joe Knapp
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1210243556
 * Also influenced by http://zovirl.com/2008/11/12/building-a-universal-remote-with-an-arduino/
 *
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 */

#include "IRremote5.h"
#include "IRremoteInt5.h"

// Provides ISR
#include <avr/interrupt.h>

irSerial_t irSerial;


void IRsend::sendLazIR(char buf[],int len, int hz){
  enableIROut(hz);
  for (int j = 0; j < len; j++) {
    mark(LazIR_HDR_MARK);
    space(LazIR_HDR_SPACE);
    for (byte i = 0b00000001; i > 0; i <<= 1) {
      if (buf[j] & i) {
        mark(LazIR_ONE_MARK);
        space(LazIR_RPT_LENGTH);
      }
      else {
        mark(LazIR_ZERO_MARK);
        space(LazIR_RPT_LENGTH);
      } 
    }
  }
}

void IRsend::mark(int time) {
  // Sends an IR mark for the specified number of microseconds.
  // The mark output is modulated at the PWM frequency.
  TIMER_ENABLE_PWM; // Enable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}

/* Leave pin off for time (given in microseconds) */
void IRsend::space(int time) {
  // Sends an IR space for the specified number of microseconds.
  // A space is no output, so the PWM output is disabled.
  TIMER_DISABLE_PWM; // Disable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}

void IRsend::enableIROut(int khz) {
  // Enables IR output.  The khz value controls the modulation frequency in kilohertz.
  // The IR output will be on pin 3 (OC2B).
  // This routine is designed for 36-40KHz; if you use it for other values, it's up to you
  // to make sure it gives reasonable results.  (Watch out for overflow / underflow / rounding.)
  // TIMER2 is used in phase-correct PWM mode, with OCR2A controlling the frequency and OCR2B
  // controlling the duty cycle.
  // There is no prescaling, so the output frequency is 16MHz / (2 * OCR2A)
  // To turn the output on and off, we leave the PWM running, but connect and disconnect the output pin.
  // A few hours staring at the ATmega documentation and this will all make sense.
  // See my Secrets of Arduino PWM at http://arcfn.com/2009/07/secrets-of-arduino-pwm.html for details.

  // Disable the Timer2 Interrupt (which is used for receiving IR)
  TIMER_DISABLE_INTR; //Timer2 Overflow Interrupt

  pinMode(TIMER_PWM_PIN, OUTPUT);
  digitalWrite(TIMER_PWM_PIN, LOW); // When not sending PWM, we want it low

  // COM2A = 00: disconnect OC2A
  // COM2B = 00: disconnect OC2B; to send signal set to 10: OC2B non-inverted
  // WGM2 = 101: phase-correct PWM with OCRA as top
  // CS2 = 000: no prescaling
  // The top value for the timer.  The modulation frequency will be SYSCLOCK / 2 / OCR2A.
  TIMER_CONFIG_KHZ(khz);
}



/////////////////////////////////////////////////////////////////////////////////////////
// initialization

IRrecv::IRrecv()
{
  //cli();
  EIMSK |= _BV(INT0); 
  EICRA |= _BV(ISC00);  
  sei();  // enable interrupts
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(13,OUTPUT);
}

//Change of pin interrupt
ISR(INT0_vect)
{
  uint32_t cTime,dTime;
  boolean currentState = PIND & _BV(2);
  cTime = micros();
  //sei();
  dTime = cTime-irSerial.prevTime;
  if (currentState){
  }
  if (currentState > irSerial.lastState && !irSerial.byteBuff.IsFull()){
    //Serial.println(int(dTime));
    if (dTime > LazIR_HDR_MARK-TOLERANCE || irSerial.bytePos > 8){
      irSerial.bytePos = 0;
      irSerial.byteFactory = 0;
    }
    else if (dTime > LazIR_ONE_MARK-TOLERANCE){
      irSerial.byteFactory |= (1 << irSerial.bytePos);
      irSerial.bytePos++;
    }
    else if (dTime > LazIR_ZERO_MARK-TOLERANCE){
      irSerial.bytePos++;
    }
    if (irSerial.bytePos == 8){
      irSerial.byteBuff.Push(irSerial.byteFactory);
      irSerial.bytePos = 0;
      irSerial.byteFactory = 0;
      //int a = irSerial.byteBuff.Pop();
      //Serial.println(a);
    }
  }
  irSerial.lastState = currentState;
  irSerial.prevTime = cTime;
}

uint8_t IRrecv::getByte(){
  uint8_t Byte;
  cli();
  if(!irSerial.byteBuff.IsEmpty()){
    Byte = irSerial.byteBuff.Pop();
  }
  sei();
  return Byte;
}

uint8_t IRrecv::serialAvailable(){
  uint8_t availability;
  cli();
  availability = !irSerial.byteBuff.IsEmpty();
  sei();
  return availability;
}
