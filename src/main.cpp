#include <iostream>
#include <fstream>
#include "Board.h"
#include "Game.h"
#include <random>
#include <chrono>


int main(int argc, char* argv[]) {
    BattleShip::Game battleship_game;

    std::ifstream configuration_file;
    configuration_file.open(argv[1]);

    if (argc == 3) { //OPTIONAL
        int seed = 0;
        sscanf(argv[2], "%d" , seed);
        std::mt19937 rand_gen(seed);
    } else { // NO SEED, USE TIME
        int time_seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 rand_gen(time_seed);
    }

    battleship_game.configure_game(configuration_file);
    battleship_game.game_type_input();
    battleship_game.setup_game();
    battleship_game.play_game();


    return 0;
}
