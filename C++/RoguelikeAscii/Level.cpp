//
// Created by tyroc on 25.11.2017.
//

#include "Level.h"

#pragma comment( lib, "Winmm.lib" )

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>

Level::Level() {

}

void Level::load(string fileName) {

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

void Level::process(Player &player, vector <Enemy> &enemies) {

    char tile;

    for (int i = 0; i < _levelData.size(); i++) {
        for (int j = 0; j < _levelData[i].size(); j++) {
            tile = _levelData[i][j];

            switch (tile){
                case '@':       //Player
                    player.setPosition(j, i);
                    break;

                case 's':       //Sname
                    enemies.push_back(Enemy("snake", tile, 1, 3, 1, 10, 10));
                    break;

                case 'g':       //Goblin
                    enemies.push_back(Enemy("goblin", tile, 2, 5, 3, 25, 50));
                    break;

                case 'b':       //Bandit
                    enemies.push_back(Enemy("bandit", tile, 3, 10, 5, 50, 100));
                    break;

                case 'D':       //Motherfucking Dragon
                    enemies.push_back(Enemy("dragon", tile, 10, 250, 250, 1000, 5000));
            }
        }
    }
}

void Level::print() {

    std::cout << string(100, '\n');

    for (int i = 0; i < _levelData.size(); i++) {
        printf("%s\n", _levelData[i].c_str());
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

void Level::battleEnemy(Player &player, int PositionX, int PositionY) {
    //TODO: Battle Function
}


char Level::getTile(int x, int y) {
    return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
    _levelData[y][x] = tile;
}





