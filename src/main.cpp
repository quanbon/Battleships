#include <iostream>
#include <fstream>
#include "Board.h"
#include "Players.h"
#include "Game.h"
#include "file_reader.h"

int main(int argc, char* argv[]) {
    BattleShip::Game battleship_game;

    std::ifstream configuration_file;
    configuration_file.open(argv[1]);

    battleship_game.configure_game(configuration_file);
    battleship_game.setup_game();


    return 0;
}
