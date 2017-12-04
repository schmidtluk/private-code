//
// Created by tyroc on 25.11.2017.
//

#ifndef ROGUELIKEASCII_GAMESYSTEM_H
#define ROGUELIKEASCII_GAMESYSTEM_H

#include "Player.h"
#include "Level.h"
#include <string>

using namespace std;

class GameSystem {
public:
    explicit GameSystem(string levelFileName);

    void GameLoop();
    void playerMove();

private:
    Player _player;
    Level _level;

};


#endif //ROGUELIKEASCII_GAMESYSTEM_H
