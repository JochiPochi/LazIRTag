/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include "IRremote5.h"

int RECV_PIN = 11;

//IRrecv irrecv(RECV_PIN);

//IRsend irsend;
IRrecv ohhyeah(5);
//decode_results results;

void setup()
{
  Serial.begin(9600);
  ohhyeah.enableIRIn();
  //irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  //if (irrecv.decode(&results)) {
  //  Serial.println(results.value, HEX);
  //  irrecv.resume(); // Receive the next value
  //}
  //char a[] = {0xAA};
  //irsend.sendLazIR(a,sizeof(a),38);
}

