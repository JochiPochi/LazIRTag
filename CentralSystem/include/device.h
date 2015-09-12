/*
 * LazIRDatabase.h
 *
 *  Created on: May 21, 2015
 *      Author: jaleman
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <iomanip>

class Device {

public:
    Device(int id_value, int ipAddress_value);
    ~Device();

    int id;
    int ipAddress;
    int batteryLevel;
    int points;
    int aux0;
    int aux1;
    int aux2;
    int aux3;
    int aux4;

};

#endif /* DEVICE_H_ */
