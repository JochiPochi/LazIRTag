/*
 * LazIRDatabase.h
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#ifndef LAZIRDATABASE_H_
#define LAZIRDATABASE_H_
#include <iostream>
#include <list>
#include <vector>
#include <stdint.h>
#include <iomanip>

#define id				0
#define fileDescriptor 	1
#define ipAddress 		2
#define batteryLevel 	3
#define rfidTagNumber 	4
#define hp 				5
#define points 			6
#define aux0 			7
#define aux1 			8
#define aux2 			9
#define aux3 			10
#define aux4 			11


class LazIR_Database {
private:
	//typedef std::vector<uint8_t> singleDevice;
	typedef std::vector<std::vector<uint8_t> > Database;
	std::vector<std::vector<uint8_t> >::iterator globalDevicesIterator;
	std::vector<uint8_t>::iterator globalDataIterator;
	int sortDevices();
	int verify();
	Database DeviceDatabase;
	int minID;
	int maxID;
public:
	LazIR_Database(int min, int max);
	bool deviceExists(uint8_t deviceID);
	int addDevice(uint8_t deviceID); //Creates a new device and sorts the list
	int removeDevice(uint8_t deviceID);
	//These functions provide information about the database
	int fetchDeviceIDList(std::vector<int> &deviceIDs);
	int numberOfDevices();
	int maxValue(int field);
	int minValue(int field);
	int devicesWithLowBattery(std::vector<int> &deviceIDs);
	int printDeviceInfo(uint8_t deviceID);
	uint8_t readValue(uint8_t deviceID, int field);
	int writeValue(uint8_t deviceID, int field, uint8_t newValue);

	virtual ~LazIR_Database();
};

#endif /* LAZIRDATABASE_H_ */
