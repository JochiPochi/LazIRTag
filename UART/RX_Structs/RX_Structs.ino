#include "packA_B.h"

int incByte = 0;	// for incoming serial data
int incLen = 0; // Initialize an incoming packet length
int packetLen = 0;
char cs = 0;

char mestyp = 0;

packA incomingA;
packB incomingB;

void setup() {
  Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
  Serial1.begin(9600);
  while (!Serial) ;

  incomingA.syncByte = 0x6E;
  incomingA.senderID = 0x00;
  incomingA.blank1 = 0x00;
  incomingA.blank2 = 0x00;

  incomingB.syncByte = 0x6E;
  incomingB.destID = 0x00;
  incomingB.blank1 = 0x00;
  incomingB.blank2 = 0x00;
}

void loop() {

  // send data only when you receive data:
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incByte = Serial1.read();
    if (mestyp == 0){
      if (incByte == 0x0A){
        incLen = 9;
        incomingA.msgType = 0x0A;
        mestyp = 0x0A;
      }
      else if(incByte == 0x0B){
        incLen = 10;
        incomingB.msgType = 0x0B;
        mestyp = 0x0B;
      }
    }

    if (mestyp == 0x0A){
      if (packetLen == 3){
        incomingA.destID = incByte;
      }
      if (packetLen == 4){
        incomingA.remHealth = incByte;
      }
      if (packetLen == 5){
        incomingA.damMult = incByte;
      }
      if (packetLen == 8){
        incomingA.checksum = incByte;
      }
    }
    if (mestyp == 0x0B){
      if (packetLen == 2){
        incomingB.senderID = incByte;
      }
      if (packetLen == 4){
        incomingB.weapID = incByte;
      }
      if (packetLen == 5){
        incomingB.playerID = incByte;
      }
      if (packetLen == 6){
        incomingB.battCond = incByte;
      }
    }
    packetLen++;


  }
  if (packetLen == incLen){
    if (mestyp == 0x0A){
      Serial.print("Sync Byte:"); 
      Serial.print(" "); 
      Serial.println(incomingA.syncByte, HEX);
      Serial.print("Message Type:"); 
      Serial.print(" "); 
      Serial.println(incomingA.msgType, HEX);
      Serial.print("Sender ID:"); 
      Serial.print(" "); 
      Serial.println(incomingA.senderID, HEX);
      Serial.print("Destination ID:"); 
      Serial.print(" "); 
      Serial.println(incomingA.destID, HEX);
      Serial.print("Remaining Health:"); 
      Serial.print(" "); 
      Serial.println(incomingA.remHealth, HEX);
      Serial.print("Damage Multiplier:"); 
      Serial.print(" "); 
      Serial.println(incomingA.damMult, HEX);
      Serial.print("Blank:"); 
      Serial.print(" "); 
      Serial.println(incomingA.blank1, HEX);
      Serial.print("Blank:"); 
      Serial.print(" "); 
      Serial.println(incomingA.blank2, HEX);
      Serial.print("Checksum:"); 
      Serial.print(" "); 
      Serial.println(incomingA.checksum, HEX);
    }
    if (mestyp == 0x0B){
      Serial.print("Sync Byte:"); 
      Serial.print(" "); 
      Serial.println(incomingB.syncByte, HEX);
      Serial.print("Message Type:"); 
      Serial.print(" "); 
      Serial.println(incomingB.msgType, HEX);
      Serial.print("Sender ID:"); 
      Serial.print(" "); 
      Serial.println(incomingB.senderID, HEX);
      Serial.print("Destination ID:"); 
      Serial.print(" "); 
      Serial.println(incomingB.destID, HEX);
      Serial.print("Weapon ID:"); 
      Serial.print(" "); 
      Serial.println(incomingB.weapID, HEX);
      Serial.print("Player ID:"); 
      Serial.print(" "); 
      Serial.println(incomingB.playerID, HEX);
      Serial.print("Battery Condition:"); 
      Serial.print(" "); 
      Serial.println(incomingB.battCond, HEX);
      Serial.print("Blank:"); 
      Serial.print(" "); 
      Serial.println(incomingB.blank1, HEX);
      Serial.print("Blank:"); 
      Serial.print(" "); 
      Serial.println(incomingB.blank2, HEX);
      Serial.print("Checksum:"); 
      Serial.print(" "); 
      Serial.println(incomingB.checksum, HEX);
    }
    Serial.println("");
    packetLen = 0;
    mestyp = 0;
  }
}
