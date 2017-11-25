//
// Created by tyroc on 25.11.2017.
//

#include "Player.h"

//Constructor
Player::Player() {
    _x = 0;
    _y = 0;
}

//Initializer
void Player::init(int level, int health, int attack, int defense, int experience) {
    _level = level;
    _health = health;
    _attack = attack;
    _defense = defense;
    _experience = experience;
}

void Player::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

void Player::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}

int Player::get_x() const {
    return _x;
}

int Player::get_y() const {
    return _y;
}

