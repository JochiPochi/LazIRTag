#include <weapon.h>

using namespace std;

Weapon::Weapon(int id_value, int ipAddress_value, int damage_value) :
        Device(id_value, ipAddress_value)
{
   damage = damage_value;
   ammo = 0;
}

Weapon::~Weapon()
{
    // Do nothing.
}
