#include <device.h>
#include <player.h>
#include <weapon.h>
#include <basestation.h>

using namespace std;

Device::Device(int id_value, int ipAddress_value)
{
   id = id_value;
   ipAddress = ipAddress_value;
   points = 0;
   aux0 = 0;
   aux1 = 0;
   aux2 = 0;
   aux3 = 0;
   aux4 = 0;
}

Device::~Device()
{
    // Do nothing.
}
