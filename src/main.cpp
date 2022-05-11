#include <iostream>
#include <fstream>
#include "Board.h"
#include "Game.h"
#include <random>
#include <chrono>


int main(int argc, char* argv[]) {
    BattleShip::Game battleship_game;
    int seed = 0;

    std::ifstream configuration_file;
    configuration_file.open(argv[1]);

    if(argc == 3) {
        seed = std::stoi(argv[2]);
    }

    battleship_game.configure_game(configuration_file, seed);
    battleship_game.game_type_input();
    battleship_game.setup_game();
    battleship_game.play_game();


    return 0;
}
