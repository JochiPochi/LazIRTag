#include <player.h>

using namespace std;

/******************* Player *******************/
Player::Player(int id, sockaddr_in address, string name) :
        Device(id, address)
{
    this->name = name;
    this->hp = 0;
    this->points = 0;
}

Player::~Player()
{
    // Do nothing.
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

void Players::addPlayer(sockaddr_in address, std::string name)
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

    /* Create player */
    Player player(id, address, name);

    /* Add player to players vector */
    this->players.push_back(player);

    return;
}

int Players::playerCount()
{
   return this->players.size();
}

/* Lookup player by name. Returns player id if found, otherwise return 0. */
int Players::findPlayer(string name)
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

bool Players::isAlive(int id)
{
    Player *player = getPlayer(id);
    if (player == NULL) {
        assert(false);
    }

    bool isAlive = (player->hp == 0) ? false : true;
    return isAlive;
}

void Players::takeDamage(int id, int damage)
{
    Player *player = getPlayer(id);
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
    Player *player = getPlayer(id);
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
    Player *player = getPlayer(id);
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
    Player *player = getPlayer(id);
    if (player == NULL) {
        assert(false);
    }

    string name = player->name;
    return name;
}

/*
 *Players::getPlayer() looks up player from players vector based on id
 * returns pointer to player object if the player id found. Otherwise return NULL
 */
Player* Players::getPlayer(int id)
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
