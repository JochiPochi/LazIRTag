/*
 * Functions.h
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}
	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}



#endif /* FUNCTIONS_H_ */
