#include <iostream>

#include "GameSystem.h"

using namespace std;

int main() {
    GameSystem gameSystem("level1.txt");

    gameSystem.GameLoop();
    return 0;
}