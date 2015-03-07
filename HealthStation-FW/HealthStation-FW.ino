// LaZIRTag Base Station Firmware
// Daniel Lefebvre && John Aleman
// February 2015

/*
Necessary Capabilities:
  -Detect RFID signal from player requesting health
  -Send packet wirelessly to central system
    - *Send message 10 times
      - Leader - 6E
      - Message Type - 0B
      - Sender ID (Base Station) - [A/B]0
      - Destination ID (Central System) - 00
      - Weapon ID - 00
      - Player (Injured) - [A/B][1-F]
      - Battery Condition (Health Station) - [00-FF]
      - Blank Byte - 00
      - Blank Byte - 00
      - Checksum - FF-Sum%FF
  -Receive incoming wi-fi packet
    - *Detect Packet -> Checksum
      - stop listening of good
      - keep listening if not
    - Leader - 6E
    - Message Type - 0A
    - Sender ID (CS) - 00
    - Dest ID (Player) - [A/B]0
    - Rem Health - [00-FF]
    - Dam Mult - 00
    - Blank Byte - 00
    - Blank Byte - 00
    - Checksum - FF-Sum%FF
  -Loop 

*/
