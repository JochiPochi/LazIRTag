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

volatile irparams_t irparams;
irSerial_t irSerial;


void IRsend::sendLazIR(char buf[],int len, int hz){
  enableIROut(hz);
  mark(LazIR_HDR_MARK);
  space(LazIR_HDR_SPACE);
  for (int j = 0; j < len; j++) {
    for (byte i = 10000000; i > 0; i >>= 1) {
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
  mark(LazIR_HDR_MARK);
  space(LazIR_HDR_SPACE); // Just to be sure
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

IRrecv::IRrecv(int recvpin)
{
  irparams.recvpin = recvpin;
  irparams.blinkflag = 0;
}

// initialization
void IRrecv::enableIRIn() {
  //cli();
  // setup pulse clock timer interrupt
  //Prescale /8 (16M/8 = 0.5 microseconds per tick)
  // Therefore, the timer interval can range from 0.5 to 128 microseconds
  // depending on the reset value (255 to 0)
  //TIMER_CONFIG_NORMAL();
  //STATE_CHANGE_ISR_CONFIG()
  EIMSK |= _BV(INT0); 
  EICRA |= _BV(ISC00);  

  //Timer2 Overflow Interrupt Enable
  //TIMER_ENABLE_INTR;

  //TIMER_RESET;

  sei();  // enable interrupts

  // initialize state machine variables
  irparams.rcvstate = STATE_IDLE;
  irparams.rawlen = 0;

  // set pin modes
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(13,OUTPUT);
}

// enable/disable blinking of pin 13 on IR processing
//void IRrecv::blink13(int blinkflag)
//{
//  irparams.blinkflag = blinkflag;
//  if (blinkflag)
//    pinMode(BLINKLED, OUTPUT);
//}

//Change of pin interrupt
ISR(INT0_vect)
{
  uint32_t cTime,dTime;
  boolean currentState = PIND & _BV(2);
  cTime = micros();
  sei();
  dTime = cTime-irSerial.prevTime;
  //  if (currentState){
  //Serial.print(int(currentState));
  //  }
  if (currentState < irSerial.lastState && !irSerial.bitBuff.IsFull()){
    //Serial.println(int(dTime));
    if (dTime > LazIR_HDR_MARK-TOLERANCE){
      char a = 2;
      irSerial.bitBuff.Push(a);
    }
    else if (dTime > LazIR_ONE_MARK-TOLERANCE){
      char a = 1;
      irSerial.bitBuff.Push(a);
    }
    else if (dTime > LazIR_ZERO_MARK-TOLERANCE){
      char a = 0;
      irSerial.bitBuff.Push(a);
    }
    if (irSerial.bitBuff.GetFront() != 2){
      irSerial.bitBuff.Pop();
    }
//        int a = irSerial.bitBuff.GetBack();
//        Serial.println(a);
  }
  irSerial.lastState = currentState;
  irSerial.prevTime = cTime;
  if (irSerial.bitBuff.GetFront()==2 && irSerial.bitBuff.GetSize()>=BITS_PER_MESS){
    //irSerial.bitBuff.Pop();
    uint8_t message[BITS_PER_MESS] = {};
    for(int i=0;i<BITS_PER_MESS;i++){
      message[i] = irSerial.bitBuff.Pop();
      //Serial.print(message[i]);
    }
    if (!irSerial.byteBuff.IsFull()){  
      //Serial.println('a');
      for(int j=0;j<MESSAGE_LENGTH;j++){
        uint8_t assembledByte = 0;
        int bitPlace = 1;
        for(int i=1+j*8;i<9+j*8;i++){
          if (message[i])
            assembledByte |= (1 << bitPlace);
            bitPlace++;
        }
        irSerial.byteBuff.Push(assembledByte);
        //uint8_t a = irSerial.byteBuff.Pop();
        //Serial.println(a);
      }
    }
  }

  //char a = bitBuff.Pop();
  //PORTC |= _BV(0);
  //  if (a == 2) digitalWrite(13, HIGH);
  //  else if (a==1) digitalWrite(13,LOW);
  //  else if (a==0) digitalWrite(13,LOW);
  //digitalWrite(13,currentState);
  //somerhing;
  //Serial.println(dTime);
  //digitalWrite(13, !digitalRead(13));
  //Serial.println(micros()-cTime);

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
  availability = irSerial.byteBuff.IsEmpty();
  sei();
  return availability;
}


void IRrecv::resume() {
  irparams.rcvstate = STATE_IDLE;
  irparams.rawlen = 0;
}




