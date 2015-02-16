#include <Arduino.h>

struct packA {
  uint8_t syncByte;
  uint8_t msgType;
  uint8_t senderID;
  uint8_t destID;
  uint8_t remHealth;
  uint8_t damMult;
  uint8_t blank1;
  uint8_t blank2;
  uint8_t checksum;
};

struct packB {
  uint8_t syncByte;
  uint8_t msgType;
  uint8_t senderID;
  uint8_t destID;
  uint8_t weapID;
  uint8_t playerID;
  uint8_t battCond;
  uint8_t blank1;
  uint8_t blank2;
  uint8_t checksum;
};
