cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Players.cpp Players.h Game.cpp Game.h Ships.cpp Ships.h Board.cpp Board.h Input_Validation.cpp Input_Validation.h file_reader.cpp file_reader.h)
