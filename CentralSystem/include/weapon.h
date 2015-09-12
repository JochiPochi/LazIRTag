#ifndef WEAPON_H_
#define WEAPON_H_

#include <device.h>

class Weapon : public Device {

public:
    Weapon(int id_value, int ipAddress_value, int damage_value);
    ~Weapon();

    int damage;
    int ammo;
};

#endif /* WEAPON_H_ */
