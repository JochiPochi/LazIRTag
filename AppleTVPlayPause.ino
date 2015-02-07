const int IRledPin = 10;

int count = 0;

void setup() {
  pinMode(IRledPin, OUTPUT);
  Serial.begin(9600);
}

void pulseIR(long microsecs) {
  // Serial.println("Interesting...");
  cli(); // cancels background stuff
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH); // takes about 3 microseconds
    delayMicroseconds(10); // 10 microseconds
    digitalWrite(IRledPin, LOW); // takes about 3 microseconds
    delayMicroseconds(10); // 10 microseconds
    // so 26 microseconds altogether
    microsecs -= 26;
  }
  sei(); // this turns them back on
}

void SendIrPacket() {
  // Serial.println("Got this far");
  // This is the code to play/pause with the Apple TV
  while(count < 1){ // Only cycling once because repeating packet twice interprets as two separate commands
    Serial.println("Leader");
    pulseIR(9000);
    delayMicroseconds(4500); // leader
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560);
    delayMicroseconds(560); // 0 bit
    pulseIR(560);
    delayMicroseconds(1690); // 1 bit
    pulseIR(560); // stop
    
    count = count + 1;
    delayMicroseconds(35380);
    // Serial.println("Delay");
  }
  count = 0;
}

void loop(void) {
  Serial.println("Sending!");
  SendIrPacket();
  delay(3000);
}
