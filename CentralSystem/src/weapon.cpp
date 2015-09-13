#include <weapon.h>

using namespace std;

Weapon::Weapon(int id, sockaddr_in address) :
        Device(id, address)
{
   this->damage = 0;
   this->ammo = 0;
}

Weapon::~Weapon()
{
    // Do nothing.
}
