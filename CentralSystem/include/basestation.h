#ifndef BASESTATION_H_
#define BASESTATION_H_

#include <device.h>

class BaseStation : public Device {

public:
    BaseStation(int id_value, int ipAddress_value);
    ~BaseStation();

    int hp;
};

#endif /* BASESTATION_H_ */
