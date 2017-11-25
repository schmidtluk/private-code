//
// Created by tyroc on 25.11.2017.
//

#include "Level.h"
#include <fstream>
#include <iostream>

Level::Level() {

}

void Level::load(string fileName) {

    //Loads the level
    ifstream file;
    file.open(fileName);

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
    
    
}

void Level::process(Player &player) {

    char tile;

    for (int i = 0; i < _levelData.size(); i++) {
        for (int j = 0; j < _levelData[i].size(); j++) {
            tile = _levelData[i][j];

            switch (tile){
                case '@':
                    player.setPosition(j, i);
                    break;
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
        case '#':
            printf("You ran into a wall.\n");
            system("PAUSE");
            break;

        case '.':
            setTile(player.get_x(), player.get_y(), '.');
            player.setPosition(newPositionX, newPositionY);
            setTile(newPositionX, newPositionY, '@');
            break;

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

char Level::getTile(int x, int y) {
    return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
    _levelData[y][x] = tile;
}




