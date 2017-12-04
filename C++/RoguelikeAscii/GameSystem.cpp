//
// Created by tyroc on 25.11.2017.
//

#include <conio.h>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include "GameSystem.h"

GameSystem::GameSystem(string levelFileName) {
    _player.init(1, 100, 10, 10, 0);

    _level.mainMenu();
    _level.load(std::move(levelFileName));
    _level.process(_player);
    _level.print(_player);

    system("PAUSE");
}

void GameSystem::GameLoop() {

    bool isDone = false;

    while (!isDone){
        _level.print(_player);
        playerMove();
    }

}

void GameSystem::playerMove() {
    char input;

    printf("Enter command (w/a/s/d): ");
    input = static_cast<char>(_getch());

    _level.movePlayer(input, _player);
}


