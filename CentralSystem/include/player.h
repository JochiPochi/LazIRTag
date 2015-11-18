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
    int weapon_id;
    void printPlayerInfo();

    friend class Players;
};

class Players {

public:
    Players();
    ~Players();
    int findPlayerByName(std::string name);
    int findPlayerByWeapon(int weapon_id);
    void printInfo(int id);
    bool addPlayer(sockaddr_in address, std::string name);
    int playerCount();
    std::string getPlayerName(int id);
    bool isAlive(int id);
    void inflictDamage(int id, unsigned int damage);
    void setPlayerHealth(int id, int hp);
    int getPlayerHealth(int id);
    int getBatteryLevel(int id);
    int getPoints(int id);
    void setPoints(int id, int points);
    void addPoints(int id, int points);
    void setWeapon(int id, int weapon_id);
    int getWeapon(int id, int weapon_id);

private:
    std::vector<Player> players;
    Player *getPlayerPointer(int id);
};

#endif /* PLAYER_H_ */
