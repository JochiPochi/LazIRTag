/*
 * LazIRDatabase.h
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <iomanip>
#include <netdb.h>
#include <cassert>

class Device {

public:
    Device(int id, sockaddr_in address);
    ~Device();

protected:
    sockaddr_in address;
    int id;
    int batteryLevel;
    int points;
    int aux0;
    int aux1;
    int aux2;
    int aux3;
    int aux4;
    void printDeviceInfo();
};

#endif /* DEVICE_H_ */
