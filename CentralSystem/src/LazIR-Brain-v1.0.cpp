//============================================================================
// Name        : LazIR-Brain.cpp
// Author      : John R. Aleman
// Version     : 1.0
// Copyright   : Mwhaha
// Description : This is the main loop of the LazIR server
//============================================================================

#include "Definitions.h"
#include "Functions.h"
#include "LazIRDatabase.h"
using namespace std;

int main(int argc, char *argv[]) {
	//Here we configure the network settings
	int sockfd;
	struct addrinfo servHints, *servinfo, *p;
	int rv;
	int numbytes;
	struct sockaddr_storage device_addr;
	char buf[MAXBUFLEN];
	socklen_t addr_len;
	char s[INET6_ADDRSTRLEN];
	memset(&servHints, 0, sizeof servHints);
	servHints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	servHints.ai_socktype = SOCK_DGRAM;
	servHints.ai_flags = AI_PASSIVE; // use my IP
	if ((rv = getaddrinfo(NULL, MYPORT, &servHints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}
	// loop through all the results and bind to the first we can
	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol))
				== -1) {
			perror("listener: socket");
			continue;
		}
		fcntl(sockfd, F_SETFL, O_NONBLOCK);
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("listener: bind");
			continue;
		}
		break;
	}
	if (p == NULL) {
		fprintf(stderr, "listener: failed to bind socket\n");
		return 2;
	}
	freeaddrinfo(servinfo);




	int gameMode = 1;
	switch (gameMode) {
	case 0: //Preliminary Mode
		//Do Stuff Here
		break;
	case 1: //Game main loop
		//Do Stuff Here
		break;
	case 2: //What happens at the end of the game
		//Do Stuff Here
		break;
	default:
		cout << "Error: An unknown value for gameMode was encountered" << endl;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int a, b, c, d, e, f, g;
	Players.addDevice(21);
	Players.addDevice(22);
	Players.addDevice(23);
	Players.addDevice(24);
	bool mau = Players.deviceExists(21);
	Players.writeValue(23, batteryLevel, 40);
	b = Players.numberOfDevices();
	cout << "number of devices: " << b << endl;
	vector<int> something;
	c = Players.devicesWithLowBattery(something);
	cout << "cc: " << c << endl;
	for (int i = 0; i < something.size(); i++) {
		cout << "elements are << " << something.at(i) << " " << endl;
	}
	a = Players.deviceExists(21);
	b = Players.numberOfDevices();
	cout << "cc: " << c << endl;
	cout << "bb: " << b << endl;
	Players.printDeviceInfo(10);
	//int foo = SUPERTEST;


	close(sockfd);
	return 0;
}

/*
 *
 * Program Starts
 * Preliminary period
 *  Players don't have health until they get tagged with a base station. So they don't make any damage.
 *  During the preliminary period new base stations and players come online. And it's the last tag of a player into a base station the team he or she will be part of.
 *  If a new player comes online after the preliminary period they can not switch and will be permanantly part of the first team they tag the base station of.
 *  Also no new base stations are allowed after the preliminary period.
 * The preliminary period ends when all parties tag a special READY RFID into the base station.
 * Once all teams are ready, countdown statrs and this is a packet sent to all players that displays the countdown on the alphanumeric and makes it vibrate every time it counts down.
 *
 * Game starts
 * Allow changes to the database
 *
 * Rules:TDM
 * Whenever you shoot somoene you get points, if you kill them you get extra points. Also if you are killed you loose points but you don;'t loose points when you are jsut shot as long as you are still alive
 * If a player gets a damage multiplier it gets notified about it and it gets added to the database
 * 	A player dies when the health points reach 0. They are considered neutral (aka damage multiplier 0) you can go to the health station and tag your rfid and get points restored.
 *
 * End of game
 * End of game happens when the health station points go to 0 and all players die.
 * Last man alive nottification is sent to player and to everyone else.
 *
 *
 * Warning, Recheck ip address mapping and solve the RFID disconenct with the wrist display.
 *
 *
 *
 *
 *********
 * Listening for incoming connections
 * if a new one is found we make a new item on our device database for it
 * if a new gun is identified it also makes a new item on a separate gun database.
 *
 *
 *
 *
 */
