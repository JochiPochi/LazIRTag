#include <player.h>
#include <iostream>
#include <cstring>

using namespace std;

/******************* Player *******************/
Player::Player(int id, sockaddr_in address, string name) :
        Device(id, address)
{
    this->name = name;
    this->hp = 0;
    this->points = 0;
    this->weapon_id = 0;
}

Player::~Player()
{
    // Do nothing.
}

void Player::printPlayerInfo()
{
    cout << "Player Properties:\n";
    cout << "   name   = " << this->name   << "\n";
    cout << "   points = " << this->points << "\n";
    cout << "   hp     = " << this->hp     << "\n";

    this->printDeviceInfo();

    return;
}

/******************* Players *******************/
Players::Players()
{
    // Do nothing.
}

Players::~Players()
{
    // Do nothing.
}

/*
 *Players::getPlayerPointer() looks up player from players vector based on id
 * returns pointer to player object if the player id found. Otherwise return NULL
 */
Player* Players::getPlayerPointer(int id)
{
    for (std::vector<Player>::iterator it = this->players.begin();
                                       it != this->players.end(); ++it) {
       if (it->id== id) {
           return &(*it);
        }
    }

    /* Player not found */
    return NULL;
}

void Players::printInfo(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    player->printPlayerInfo();
    return;
}

bool Players::addPlayer(sockaddr_in address, std::string name)
{
    bool id_obtained = false;
    int id = 1;

    /* Determine player id */
    while (!id_obtained) {
        bool found_matching_id = false;
        for(std::vector<Player>::iterator it = this->players.begin();
                                          it != this->players.end(); ++it) {
           if (it->id == id) {
                found_matching_id = true;
                id++;
                break;
            }
        }

        if (found_matching_id == false) {
            id_obtained = true;
        }
    }

    /* Make sure name is not taken */
    int dummy_id = findPlayerByName(name);
    if (dummy_id != 0) {
        return false;
    }

    /* Make sure address is not already taken */
    for(std::vector<Player>::iterator it = this->players.begin();
                                      it != this->players.end(); ++it) {
       if (memcmp(&(it->address), &address, sizeof(sockaddr_in))) {
            return false;
        }
    }

    /* Create player */
    Player player(id, address, name);

    /* Add player to players vector */
    this->players.push_back(player);

    return true;
}

int Players::playerCount()
{
   return this->players.size();
}

/* Lookup player by name. Returns player id if found, otherwise return 0. */
int Players::findPlayerByName(string name)
{
    for (std::vector<Player>::iterator it = this->players.begin();
                                       it != this->players.end(); ++it) {
       if (it->name == name) {
           return it->id;
        }
    }

    /* Player not found */
    return 0;
}

int Players::findPlayerByWeapon(int weapon_id)
{
    for (std::vector<Player>::iterator it = this->players.begin();
                                       it != this->players.end(); ++it) {
       if (it->weapon_id == weapon_id) {
           return it->id;
        }
    }

    /* Player not found */
    return 0;
}

bool Players::isAlive(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    bool isAlive = (player->hp == 0) ? false : true;
    return isAlive;
}

void Players::takeDamage(int id, int damage)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    /* Player cannot lose more hp than the player currently has */
    int effectiveDamage = (damage > player->hp) ? player->hp : damage;
    player->hp -= effectiveDamage;
    return;
}

/*
 * Players::getPlayerHealth() determines heath of a player
 * returns string to players name.
 */
int Players::getPlayerHealth(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    return player->hp;
}

/*
 * Players::setPlayerHealth() sets the health of a player associated with a given id
 */
void Players::setPlayerHealth(int id, int hp)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    player->hp = hp;
    return;
}

/*
 * Players::getPlayerName() determines the name of player associated with a given id
 * returns string to players name.
 */
std::string Players::getPlayerName(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    string name = player->name;
    return name;
}


int Players::getBatteryLevel(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    int battery = player->batteryLevel;
    return battery;
}

int Players::getPoints(int id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    int points = player->points;
    return points;
}

void Players::setWeapon(int id, int weapon_id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    player->weapon_id = weapon_id;
    return;
}

int Players::getWeapon(int id, int weapon_id)
{
    Player *player = getPlayerPointer(id);
    if (player == NULL) {
        assert(false);
    }

    return player->weapon_id;
