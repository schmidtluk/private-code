//
// Created by tyroc on 26.11.2017.
//

#ifndef ROGUELIKEASCII_ENEMY_H
#define ROGUELIKEASCII_ENEMY_H

#include <string>

using namespace std;

class Enemy {
public:
    Enemy(string name, char tile, int level, int attack, int defense, int health, int experienceValue);

private:
    string _name;
    char _tile;

    int _level;
    int _attack;
    int _defense;
    int _health;
    int _experienceValue;
};


#endif //ROGUELIKEASCII_ENEMY_H
