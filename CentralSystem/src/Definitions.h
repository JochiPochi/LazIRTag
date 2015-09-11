#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BASESTATION_MIN_ID 0x00
#define BASESTATION_MAX_ID 0x0F
#define PLAYER_MIN_ID 0x10
#define PLAYER_MAX_ID 0x8F
#define OTHER_MIN_ID 0x90
#define OTHER_MAX_ID 0xFF

LazIR_Database BaseStations(BASESTATION_MIN_ID, BASESTATION_MAX_ID);
LazIR_Database Players(PLAYER_MIN_ID, PLAYER_MAX_ID);
LazIR_Database Others(OTHER_MIN_ID, OTHER_MAX_ID);

#define MYPORT "5050" // the port users will be connecting to
#define MAXBUFLEN 100
