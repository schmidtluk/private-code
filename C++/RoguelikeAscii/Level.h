//
// Created by tyroc on 25.11.2017.
//

#ifndef ROGUELIKEASCII_LEVEL_H
#define ROGUELIKEASCII_LEVEL_H

#include <vector>
#include <string>

#include "Player.h"

using namespace std;

class Level {
public:
    Level();

    void load(string fileName);
    void process(Player &player);
    void print();

    void movePlayer(char input, Player &player);


    char getTile(int x, int y);
    void setTile(int x, int y, char tile);

private:
    vector <string> _levelData;

    void move(char moveTile, Player &player, int newPositionX, int newPoitionY);
};


#endif //ROGUELIKEASCII_LEVEL_H
