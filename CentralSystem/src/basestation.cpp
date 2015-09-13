#include <basestation.h>

using namespace std;

BaseStation::BaseStation(int id, sockaddr_in address) :
        Device(id, address)
{
    this->hp = 0;
}

BaseStation::~BaseStation()
{
    // Do nothing.
}
