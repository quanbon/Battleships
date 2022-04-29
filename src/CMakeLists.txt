cmake_minimum_required(VERSION 3.21)
project(Battleships)

set(CMAKE_CXX_STANDARD 14)

add_executable(Battleships main.cpp Players.cpp Players.h Game.cpp Game.h Ships.cpp Ships.h Board.cpp Board.h Move.cpp Move.h Input_Validation.cpp Input_Validation.h)
