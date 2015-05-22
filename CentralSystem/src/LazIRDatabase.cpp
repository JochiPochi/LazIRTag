/*
 * LazIRDatabase.cpp
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#include "LazIRDatabase.h"

LazIR_Database::LazIR_Database(int min, int max) {
	// TODO Auto-generated constructor stub
	this->minID = min;
	this->maxID = max;
}

//Public Functions

bool LazIR_Database::LazIR_Database::deviceExists(int deviceID) {
	bool result = true;
	return result;
}
int LazIR_Database::addDevice(int deviceID) {
	int error = 0;
	return error;
}
int LazIR_Database::removeDevice(int deviceId) {
	int error = 0;
	return error;
}
//These functions provide information about the database
//int LazIR_Database::fetchDeviceIDList(deviceIDs result) {int
//	int error;
//	return error;
//}
int LazIR_Database::numberOfDevices() {
	int result = 0;
	return result;
}
int LazIR_Database::maxValue(int field) {
	int result = 0;
	return result;
}
int LazIR_Database::minValue(int field) {
	int result = 0;
	return result;
}
//deviceIDs LazIR_Database::devicesWithLowBattery(deviceIDs result) {
//	int error;
//	return error;
//}
int LazIR_Database::printDeviceInfo(int deviceID) {
	int error = 0;
	return error;
}
uint8_t LazIR_Database::readValue(int deviceID, int field) {
	int result = 0;
	return result;
}

int LazIR_Database::writeValue(int deviceID, int field, uint8_t newValue) {
	int error = 0;
	return error;
}


LazIR_Database::~LazIR_Database() {
	// TODO Auto-generated destructor stub
}

