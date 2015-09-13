#ifndef BASESTATION_H_
#define BASESTATION_H_

#include <device.h>

class BaseStation : public Device {

public:
    BaseStation(int id, sockaddr_in address);
    ~BaseStation();

private:
    int hp;
};

#endif /* BASESTATION_H_ */
