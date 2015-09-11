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

bool LazIR_Database::LazIR_Database::deviceExists(uint8_t deviceID) {
	bool result = false;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	int a = this->DeviceDatabase.size();
	if (a == 0) {
		result = false;
	} else {
		for (devicesIterator = DeviceDatabase.begin();
				devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
			if (devicesIterator->at(0) == deviceID) {
				result = true;
			}
		}
	}
	return result;
}
int LazIR_Database::addDevice(uint8_t deviceID) {
	int error = 0;
	if (deviceExists(deviceID)) {
		error = 1;
		std::cout << "Error " << error
				<< " while adding new device to the database, device already exists."
				<< std::endl;
	} else {
		std::vector<uint8_t> newDevice;
		newDevice.push_back(deviceID);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		newDevice.push_back(0);
		DeviceDatabase.push_back(newDevice);
		error = 0;
	}
	return error;
}
int LazIR_Database::removeDevice(uint8_t deviceID) {
	int error = -1;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		if (devicesIterator->at(0) == deviceID) {
			DeviceDatabase.erase(devicesIterator);
			error = 0;
			break;
		}
	}
	return error;
}
//These functions provide information about the database
int LazIR_Database::fetchDeviceIDList(std::vector<int> &deviceIDs) {
	int error = 0;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	if (DeviceDatabase.size() == 0) {
		error = -1;
	} else {
		for (devicesIterator = DeviceDatabase.begin();
				devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
			deviceIDs.push_back(devicesIterator->at(id));
		}
	}
	error = DeviceDatabase.size();
	return error;
}
int LazIR_Database::numberOfDevices() {
	int result = DeviceDatabase.size();
	return result;
}
int LazIR_Database::maxValue(int field) {
	int result = 0;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		if (devicesIterator->at(field) > result) {
			result = devicesIterator->at(field);
		}
	}
	return result;
}
int LazIR_Database::minValue(int field) {
	int result = 0xFF;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		if (devicesIterator->at(field) < result) {
			result = devicesIterator->at(field);
		}
	}
	return result;
}
int LazIR_Database::devicesWithLowBattery(std::vector<int> &deviceIDs) {
	int error = 0;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	if (this->DeviceDatabase.size() == 0) {
		error = -1;
	} else {
		for (devicesIterator = DeviceDatabase.begin();
				devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
			if (devicesIterator->at(batteryLevel) < 20) {
				deviceIDs.push_back(devicesIterator->at(id));
				error++;
			}
		}
	}
	return error;
}
int LazIR_Database::printDeviceInfo(uint8_t deviceID) { ///This functions is still not made
	int error = 0;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	std::vector<uint8_t>::iterator dataIterator;
	std::cout << "Database   " << "mau" << std::endl;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		for (dataIterator = devicesIterator->begin();
				dataIterator != devicesIterator->end(); ++dataIterator){
			std::cout << std::setw(5) << int(*dataIterator);
		}
		std::cout << std::endl;
	}
	return error;
}
uint8_t LazIR_Database::readValue(uint8_t deviceID, int field) {
	int result = 0xFF;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		if (devicesIterator->at(0) == deviceID) {
			result = devicesIterator->at(field);
		}
	}
	return result;
}

int LazIR_Database::writeValue(uint8_t deviceID, int field, uint8_t newValue) {
	int error = 0;
	std::vector<std::vector<uint8_t> >::iterator devicesIterator;
	for (devicesIterator = DeviceDatabase.begin();
			devicesIterator != DeviceDatabase.end(); ++devicesIterator) {
		if (devicesIterator->at(0) == deviceID) {
			devicesIterator->at(field) = newValue;
			return error;
		}
	}
	error = -1;
	return error;
}

LazIR_Database::~LazIR_Database() {
// TODO Auto-generated destructor stub
}

