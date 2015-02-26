// Initialize Switch States
int sS1 = 0; 
int pSS1 = 0;
int sS2 = 0; 
int pSS2 = 0;
int sS3 = 0; 
int pSS3 = 0;
int sS4 = 0; 
int pSS4 = 0;
int sS5 = 0; 
int pSS5 = 0;
int sS6 = 0; 
int pSS6 = 0;

uint8_t debounce = 500;

// Define Button Pins
#define switchOut1 13
#define switchIn1 12
#define switchOut2 11
#define switchIn2 10
#define switchOut3 9
#define switchIn3 8
#define switchOut4 7
#define switchIn4 6
#define switchOut5 5
#define switchIn5 4
#define switchOut6 3
#define switchIn6 2

// Initialize Packet Bytes
char syncByte = 0x6E; // Same with each message
char msgType; // Changes depending on message
char senderID;
char destID;
char remHealth;
char damMult;
char weapID;
char playerID;
char battCond;
char blank = 0x00; // Will be used twice to add room for expansion
char checksum;

void setup(){
  Serial.begin(9600); // Initialize Serial Comms
  pinMode(switchOut1, OUTPUT); 
  pinMode(switchIn1, INPUT); 
  digitalWrite(switchOut1, HIGH);
  pinMode(switchOut2, OUTPUT); 
  pinMode(switchIn2, INPUT); 
  digitalWrite(switchOut2, HIGH);
  pinMode(switchOut3, OUTPUT); 
  pinMode(switchIn3, INPUT); 
  digitalWrite(switchOut3, HIGH);
  pinMode(switchOut4, OUTPUT); 
  pinMode(switchIn4, INPUT); 
  digitalWrite(switchOut4, HIGH);
  pinMode(switchOut5, OUTPUT); 
  pinMode(switchIn5, INPUT); 
  digitalWrite(switchOut5, HIGH);
  pinMode(switchOut6, OUTPUT); 
  pinMode(switchIn6, INPUT); 
  digitalWrite(switchOut6, HIGH);
}

void loop(){
  sS1 = digitalRead(switchIn1); 
  sS2 = digitalRead(switchIn2); 
  sS3 = digitalRead(switchIn3); 
  sS4 = digitalRead(switchIn4);
  sS5 = digitalRead(switchIn5); 
  sS6 = digitalRead(switchIn6);
  if (sS1  == 1 || sS2 == 1 || sS3 == 1 || sS4 == 1 || sS5 == 1 || sS6 == 1){
    if (sS1 != pSS1 && sS1 == 1){ // If it's button 1
      msgType = 0x0B;
      senderID = 0xA0; // Send customized info for this example packet
      destID = 0x00;
      weapID = 0x00; // From Team A's health station, no weapon
      playerID = 0xA9;
      battCond = 0xFC;
    }
    if (sS2 != pSS2 && sS2 == 1){ // or button 2
      msgType = 0x0B;
      senderID = 0xB0; // Change the bytes to test comms
      destID = 0x00;
      weapID = 0x00; // From Team B's health station
      playerID = 0xBD;
      battCond = 0xFE;
    }
    if (sS3 != pSS3 && sS3 == 1){ // or even button 3
      msgType = 0x0B;
      senderID = 0xA9;
      destID = 0x00;
      weapID = 0xAD; // Player got shot with this gun
      playerID = 0xBD;
      battCond = 0xFF;
    }
    if(sS4 != pSS4 && sS4 == 1){
      msgType = 0x0A;
      senderID = 0x00;
      destID = 0xA0;
      remHealth = 0xDA;
      damMult = 0x01;
    }
    if(sS5 != pSS5 && sS5 == 1){
      msgType = 0x0A;
      senderID = 0x00;
      destID = 0xB0;
      remHealth = 0xC2;
      damMult = 0x01;
    }
    if(sS6 != pSS6 && sS6 == 1){
      msgType = 0x0A;
      senderID = 0x00;
      destID = 0xA9;
      remHealth = 0x3D;
      damMult = 0x02;
    }

    //    for (int i = 1; i == 20; i++){
    if (msgType == 0x0A){
      checksum = (0xFF - (syncByte+msgType+senderID+destID+remHealth+damMult));
//      Serial.write(syncByte); 
//      Serial.write(msgType); 
//      Serial.write(senderID); 
//      Serial.write(destID);
//      Serial.write(remHealth);
//      Serial.write(damMult);
//      Serial.write(blank);
//      Serial.write(blank);
//      Serial.write(checksum);
      Serial.println(syncByte, HEX);
      Serial.println(msgType, HEX);
      Serial.println(senderID, HEX);
      Serial.println(destID, HEX);
      Serial.println(remHealth, HEX);
      Serial.println(damMult, HEX);
      Serial.println(blank, HEX);
      Serial.println(blank, HEX);
      Serial.println(checksum, HEX);
      //        delay(1);
      //      }
    }
    //    for (int i = 1; i == 20; i++){
    if (msgType == 0x0B){
      checksum = (0xFF - (syncByte+msgType+senderID+destID+weapID+playerID+battCond));
      Serial.write(syncByte); // Send packet with customized info based on button
      Serial.write(msgType);
      Serial.write(senderID);
      Serial.write(destID);
      Serial.write(weapID);
      Serial.write(playerID);
      Serial.write(battCond);
      Serial.write(blank);
      Serial.write(blank);
      Serial.write(checksum);
      //        delay(1);
      //      }
    }
  }
  // Update Switch State Variables
  pSS1 = sS1; 
  pSS2 = sS2; 
  pSS3 = sS3; 
  pSS4 = sS4; 
  pSS5 = sS5; 
  pSS6 = sS6;
}









