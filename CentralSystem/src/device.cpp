#include <device.h>
#include <player.h>
#include <weapon.h>
#include <basestation.h>

using namespace std;

Device::Device(int id, sockaddr_in address)
{
    this->id = id;
    this->address = address;
    this->points = 0;
    this->aux0 = 0;
    this->aux1 = 0;
    this->aux2 = 0;
    this->aux3 = 0;
    this->aux4 = 0;
}

Device::~Device()
{
    // Do nothing.
}
