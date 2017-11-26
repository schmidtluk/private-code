//
// Created by tyroc on 26.11.2017.
//

#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int experienceValue) {
    _name = name;
    _tile = tile;
    _level = level;
    _attack = attack;
    _defense = defense;
    _health = health;
    _experienceValue = experienceValue;
}
