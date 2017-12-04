//
// Created by tyroc on 26.11.2017.
//

#include <random>
#include <ctime>
#include <utility>
#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int experienceValue) {
    _name = std::move(name);
    _tile = tile;
    _level = level;
    _attack = attack;
    _defense = defense;
    _health = health;
    _experienceValue = experienceValue;
}

int Enemy::attack() {
    static default_random_engine randomEngine(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> attackRoll (0, _attack);

    return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack) {
    attack -= _defense;

    //check if attack does damage
    if (attack > 0){
        _health -= attack;

        //check if dead
        if (_health <= 0){
            return _experienceValue;
        }
    }

    return 0;
}

void Enemy::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

void Enemy::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}

const string &Enemy::get_name() const {
    return _name;
}


