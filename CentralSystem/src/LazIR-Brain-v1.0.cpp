//============================================================================
// Name        : 0.cpp
// Author      : John R. Aleman
// Version     :
// Copyright   : Mwhaha
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
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
#include "Definitions.h"
#include "Functions.h"
#include "LazIRDatabase.h"
using namespace std;


int main() {
	LazIR_Database BaseStations(BASESTATION_MIN_ID, BASESTATION_MAX_ID);
	LazIR_Database Players(PLAYER_MIN_ID, PLAYER_MIN_ID);
	LazIR_Database Others(OTHER_MIN_ID, OTHER_MIN_ID);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//int foo = SUPERTEST;
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
