#include <iostream>
#include <fstream>
#include "Board.h"
#include "Players.h"
#include "file_reader.h"

int main(int argc, char* argv[]) {
    int board_num_rows, board_num_cols;
    std::vector<BattleShip::Ships> ship_container;
    std::ifstream configuration_file;
    configuration_file.open(argv[1]);
    read_config_file(configuration_file, board_num_rows, board_num_cols, ship_container);






    return 0;
}
