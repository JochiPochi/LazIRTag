/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:

//Pulse parameters for LazIR
#define LazIR_HDR_MARK	1000
#define LazIR_HDR_SPACE	400
#define LazIR_ONE_MARK	800
#define LazIR_ZERO_MARK	600
#define LazIR_RPT_LENGTH 400
#define LazIR_DOUBLE_SPACE_USECS  500

#define TOLERANCE 90  // percent tolerance in measurements
#define LTOL (1.0 - TOLERANCE/100.) 
#define UTOL (1.0 + TOLERANCE/100.) 

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  pinMode(7,INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(7)){
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);               // wait for a second
  }
  else {
  char a[] = {'a','b'};
  sendLazIR(a,sizeof(a),38);
  delay(2000);
  }
}

void sendLazIR(char buf[],int len, int hz){
  //enableIROut(hz);
  for (int j = 0; j < len; j++) {
    mark(LazIR_HDR_MARK);
    space(LazIR_HDR_SPACE);
    for (byte i = 0b10000000; i > 0; i >>= 1) {
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
  //mark(LazIR_HDR_MARK);
  //space(LazIR_HDR_SPACE); // Just to be sure
}

void mark(int time) {
  // Sends an IR mark for the specified number of microseconds.
  // The mark output is modulated at the PWM frequency.
  digitalWrite(led, HIGH); // Enable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}

/* Leave pin off for time (given in microseconds) */
void space(int time) {
  // Sends an IR space for the specified number of microseconds.
  // A space is no output, so the PWM output is disabled.
  digitalWrite(led, LOW); // Disable pin 3 PWM output
  if (time > 0) delayMicroseconds(time);
}
