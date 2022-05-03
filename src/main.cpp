#include <iostream>
#include <fstream>
#include "Board.h"
#include "Players.h"
#include "Game.h"
#include "file_reader.h"

int main(int argc, char* argv[]) {
    BattleShip::Game battleship_game;
    int board_num_rows, board_num_cols;
    std::vector<BattleShip::Ships> ship_container;

    std::ifstream configuration_file;
    configuration_file.open(argv[1]);

    battleship_game.configure_game(configuration_file, board_num_rows, board_num_cols, ship_container);


    return 0;
}
