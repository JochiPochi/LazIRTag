int sS = 0;
int pSS = 0;

#define switchOut 10
#define switchIn 8

char syncByte = 0x6E;
char msgType = 0x0B;
char senderID = 0xA0;
char destID = 0x00;
char weapID = 0x00;
char playerID = 0xA1;
char battCond = 0xF7;
char blank = 0x00;
char checksum = (0xFF - (syncByte+msgType+senderID+destID+weapID+playerID+battCond));

void setup(){
  Serial.begin(9600);
  pinMode(switchOut, OUTPUT);
  pinMode(switchIn, INPUT);
  digitalWrite(switchOut, HIGH);
}

void loop(){
  sS = digitalRead(switchIn);
  if (sS != pSS && sS == 1){
    // Serial.print(checksum, HEX);
    Serial.write(syncByte);
    Serial.write(msgType);
    Serial.write(senderID);
    Serial.write(destID);
    Serial.write(weapID);
    Serial.write(playerID);
    Serial.write(battCond);
    Serial.write(blank);
    Serial.write(blank);
    Serial.write(checksum);
  }
  pSS = sS;
}
