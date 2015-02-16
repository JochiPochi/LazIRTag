// LaZIRTag Player Firmware
// Daniel Lefebvre && John Aleman
// February 2015

/*
Necessary Capabilities:
  -Detect IR signals coming from guns
    - *Detect Signal -> Checksum
      - stop listening if good
      - keep listening if not
    - Leader - 6E
    - Weapon ID - [A-B][0-F]
    - Player ID (Shooter) - [A/B][1-F]
    - Weapon Battery Condition - [00-FF]
    - Checksum - FF-Sum%FF
  -Repeat incoming packet with appended information wirelessly to CS
    - *Send message 10 times
    - Leader - 6E
    - Message Type - 0B
    - Sender ID (Player) - [A/B](0,[1-F])
    - Destination ID (Central System) - 00
    - Weapon ID - [A-B][0-F]
    - Player (Shooter) - [A/B][1-F]
    - Battery Condition (Weapon) - [00-FF]
    - Blank Byte - 00
    - Blank Byte - 00
    - Checksum - FF-Sum%FF
  -Receive incoming wireless packet
  -

*/
