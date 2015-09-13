#ifndef PLAYER_H_
#define PLAYER_H_

#include <device.h>
#include <vector>

class Player : public Device {

public:
    Player(int id, sockaddr_in address, std::string name);
    ~Player();

private:
    std::string name;
    int hp;
    int points;

    friend class Players;
};

class Players {

public:
    Players();
    ~Players();
    int findPlayer(std::string name);
    void addPlayer(sockaddr_in address, std::string name);
    int playerCount();
    bool isAlive(int id);
    void takeDamage(int id, int damage);
    void setPlayerHealth(int id, int hp);
    int getPlayerHealth(int id);
    std::string getPlayerName(int id);

private:
    std::vector<Player> players;
    Player *getPlayer(int id);
};

#endif /* PLAYER_H_ */
