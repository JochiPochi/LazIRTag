int incomingByte = 0;	// for incoming serial data

void setup() {
  Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
  Serial1.begin(9600);
  while (!Serial) ;
}

void loop() {

  // send data only when you receive data:
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial1.read();

    Serial.print(incomingByte, HEX);  // print as an ASCII-encoded hexadecimal
    Serial.println("");      // prints another carriage return
  }
}


