/*
 * Functions.h
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "Definitions.h"

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}
	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

void parsePacket(char *packet, int size){
	//This gets a pointer to a byte array and updates the database
}

bool checkIncomingConnections(){
	//This function checks to see if there are any connections on the queue and returns 1 if true
	//It uses the byte pointer to fill out the info in the wireless packet
}

bool checkRules(){
	//Reads the wining parameters to see if anyone won
}



#endif /* FUNCTIONS_H_ */
