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

    int attack();
    int takeDamage(int attack);

    void setPosition(int x, int y);
    void getPosition(int &x, int &y);

    const string &get_name() const;

private:
    string _name;
    char _tile;

    int _level;
    int _attack;
    int _defense;
    int _health;
    int _experienceValue;

    int _x;
    int _y;
};


#endif //ROGUELIKEASCII_ENEMY_H
