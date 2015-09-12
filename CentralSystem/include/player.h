#ifndef PLAYER_H_
#define PLAYER_H_

#include <device.h>

class Player : public Device {

public:
    Player(int id_value, int ipAddress_value, std::string name_value);
    ~Player();

    std::string name;
    int hp;
    int points;
};

#endif /* PLAYER_H_ */
