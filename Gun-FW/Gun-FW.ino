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

IRsend irsend;
IRrecv ohhyeah;
//decode_results results;

void setup()
{
  Serial.begin(9600);
  //ohhyeah.enableIRin();
  //irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  char mau;
  
  
  while(ohhyeah.serialAvailable()){
    mau = ohhyeah.getByte();
    Serial.print(mau);
  }


  //Serial.println();
  char a[] = {'a','b','c'};
  irsend.sendLazIR(a,sizeof(a),38);
  delay(500);
  
  
}

