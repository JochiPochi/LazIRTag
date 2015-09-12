#include <player.h>

using namespace std;

Player::Player(int id_value, int ipAddress_value, string name_value) :
        Device(id_value, ipAddress_value)
{
    name = name_value;
    hp = 0;
    points = 0;
}

Player::~Player()
{
    // Do nothing.
}
