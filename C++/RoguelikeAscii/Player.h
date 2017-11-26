//
// Created by tyroc on 25.11.2017.
//

#ifndef ROGUELIKEASCII_PLAYER_H
#define ROGUELIKEASCII_PLAYER_H


class Player {
public:
    Player();
    void init(int level, int health, int attack, int defense, int experience);

    int attack();
    void addExperience(int xp);
    bool takeDamage(int attack);

    void printStat(int counter);

    void setPosition(int x, int y);
    void getPosition(int &x, int &y);

    int get_x() const;
    int get_y() const;


private:
    //Properties
    int _level;
    int _health;
    int _attack;
    int _defense;
    int _experience;

    //Position
    int _x;
    int _y;

};


#endif //ROGUELIKEASCII_PLAYER_H
