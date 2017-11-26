#include <iostream>

#include "GameSystem.h"

using namespace std;

int main() {

    //TODO: Add Level Loader
    //TODO: Add Main Menu
    GameSystem gameSystem("level1");

    gameSystem.GameLoop();
    return 0;
}