//
// Created by tyroc on 25.11.2017.
//

#include "Level.h"

#pragma comment( lib, "Winmm.lib" )

#include <iostream>
#include <Windows.h>
#include <fstream>

Level::Level() = default;

void Level::load(string fileName) {
    //Clear Level

    _levelData.clear();

    //Loads the level
    ifstream file;
    file.open(".\\Levels\\" + fileName + ".txt");

    if(!file.fail()){
        string line;

        while (getline(file, line)){
            _levelData.push_back(line);
        }
    } else{
        perror(fileName.c_str());
        system("PAUSE");
        exit(1);
    }

    file.close();

    //TODO: Add Music Player
}


void Level::process(Player &player) {

    char tile;

    for (int i = 0; i < _levelData.size(); i++) {
        for (int j = 0; j < _levelData[i].size(); j++) {
            tile = _levelData[i][j];

            switch (tile){
                case '@':       //Player
                    player.setPosition(j, i);
                    break;

                case 's':       //Sname
                    _enemies.emplace_back("Snake", tile, 1, 3, 1, 10, 10);
                    _enemies.back().setPosition(j, i);
                    break;

                case 'g':       //Goblin
                    _enemies.emplace_back("Goblin", tile, 2, 5, 3, 25, 50);
                    _enemies.back().setPosition(j, i);
                    break;

                case 'b':       //Bandit
                    _enemies.emplace_back("Bandit", tile, 3, 10, 5, 50, 100);
                    _enemies.back().setPosition(j, i);
                    break;

                case 'D':       //Motherfucking Dragon
                    _enemies.emplace_back("Dragon", tile, 10, 250, 250, 1000, 5000);
                    _enemies.back().setPosition(j, i);
                    break;

                default:
                    break;
            }
        }
    }
}

void Level::print(Player player) {

    int counter=0;

    std::cout << string(100, '\n');

    for (auto &i : _levelData) {
        if(counter < 6){
            printf("%s  ", i.c_str());
            player.printStat(counter);
            counter++;
        } else{
            printf("%s\n", i.c_str());
        }
    }

    printf("\n");
}

void Level::move(char moveTile, Player &player, int newPositionX, int newPositionY) {

    switch (moveTile){
        case '.':
            setTile(player.get_x(), player.get_y(), '.');
            player.setPosition(newPositionX, newPositionY);
            setTile(newPositionX, newPositionY, '@');
            break;

        case '#':
            break;

        default:
            battleEnemy(player, newPositionX, newPositionY);

    }
}

void Level::movePlayer(char input, Player &player) {

    int positionX;
    int positionY;

    int newPositionX;
    int newPositionY;

    player.getPosition(positionX, positionY);

    char moveTile;

    switch (input){
        case 'w':               //up
            newPositionX = positionX;
            newPositionY = positionY-1;

            moveTile = getTile(newPositionX, newPositionY);
            move(moveTile, player, newPositionX, newPositionY);

            break;

        case 's':               //down
            newPositionX = positionX;
            newPositionY = positionY+1;

            moveTile = getTile(newPositionX, newPositionY);
            move(moveTile, player, newPositionX, newPositionY);

            break;

        case 'a':               //left
            newPositionX = positionX-1;
            newPositionY = positionY;

            moveTile = getTile(newPositionX, newPositionY);
            move(moveTile, player, newPositionX, newPositionY);

            break;

        case 'd':               //right
            newPositionX = positionX+1;
            newPositionY = positionY;

            moveTile = getTile(newPositionX, newPositionY);
            move(moveTile, player, newPositionX, newPositionY);

            break;

        default:
            printf("INVALID INPUT!\n");
            system("PAUSE");
            break;
    }
}

/*void Level::updateEnemies(Player &player) {

    for (int i = 0; i < _enemies.size(); ++i) {

    }
}*/

void Level::battleEnemy(Player &player, int TargetX, int TargetY) {
    int enemyX;
    int enemyY;
    int playerX;
    int playerY;
    int attackRoll;
    int attackResult;

    player.getPosition(playerX, playerY);

    for (auto &_enemie : _enemies) {
        _enemie.getPosition(enemyX, enemyY);

        if (TargetX == enemyX && TargetY == enemyY) {
            //Battle
            attackRoll = player.attack();
            printf("\nPlayer attacking %s with roll of: %d\n", _enemie.get_name().c_str(), attackRoll);
            attackResult = _enemie.takeDamage(attackRoll);

            if (attackResult != 0) {
                setTile(TargetX, TargetY, '.');
                print(player);
                printf("The enemy died. You horrendous monster!!\n");
                system("PAUSE");

                player.addExperience(attackResult);
            } else {

                //Monster fighting
                attackRoll = _enemie.attack();
                printf("%s attacked Player with a roll of %d\n", _enemie.get_name().c_str(), attackRoll);
                attackResult = player.takeDamage(attackRoll);

                if (attackResult != 0) {
                    setTile(playerX, playerY, 'X');
                    print(player);
                    printf("YOU DIED!\n");
                    system("PAUSE");

                    exit(0);
                }
            }
            system("PAUSE");
        }
    }
}


char Level::getTile(int x, int y) {
    return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
    _levelData[y][x] = tile;
}

void Level::mainMenu() {

    //Load ASCII File Main
    this->load("main");

    //Print main menu
    for (auto &i : _levelData) {
        printf("%s\n", i.c_str());
    }

    system("PAUSE");
}








