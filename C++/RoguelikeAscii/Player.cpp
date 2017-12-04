//
// Created by tyroc on 25.11.2017.
//

#include "Player.h"
#include <random>
#include <ctime>
#include <cstdio>

using namespace std;

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

int Player::attack() {
    static default_random_engine randomEngine(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<int> attackRoll (0, _attack);

    return attackRoll(randomEngine);
}

void Player::addExperience(int xp) {
    _experience += xp;

    //Level Up !!
    while(_experience > 50){
        printf("Leveld Up! Another step to adulthood taken.\n");

        _experience -= 50;
        _attack += 10;
        _defense += 5;
        _health += 10;
        _level++;

        system("PAUSE");
    }
}

bool Player::takeDamage(int attack) {
    attack -= _defense;

    //check if attack does damage
    if (attack > 0){
        _health -= attack;

        //check if dead
        if (_health <= 0){
            return true;
        }
    }

    return false;
}

void Player::printStat(int counter) {
    switch (counter){
        case 0:
            printf("-----Player Stats-----\n");
            break;

        case 1:
            printf("Level: %d\n", _level);
            break;

        case 2:
            if (_health >= 0){
                printf("Health: %d\n", _health);
            } else
                printf("Health: 0\n");
            break;

        case 3:
            printf("Attack: %d\n", _attack);
            break;

        case 4:
            printf("Defense: %d\n", _defense);
            break;

        case 5:
            printf("Experience: %d\n", _experience);
            break;

        default:
            break;
    }
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




