#ifndef WEAPON_H_
#define WEAPON_H_

#include <device.h>

class Weapon : public Device {

public:
    Weapon(int id, sockaddr_in address);
    ~Weapon();

private:
    int damage;
    int ammo;
};

#endif /* WEAPON_H_ */
