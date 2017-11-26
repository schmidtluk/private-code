cmake_minimum_required(VERSION 3.8)
project(RoguelikeAscii)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GameSystem.cpp GameSystem.h Player.cpp Player.h Level.cpp Level.h Enemy.cpp Enemy.h)
add_executable(RoguelikeAscii ${SOURCE_FILES})