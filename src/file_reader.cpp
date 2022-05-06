//
// Created by harle on 5/2/2022.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "Ships.h"
#include "file_reader.h"



void BattleShip::read_config_file (std::ifstream& src, int& num_rows, int& num_cols, std::vector<BattleShip::Ships>& ship_container) {
    int ship_container_size;
    src >> num_rows;
    src >> num_cols;
    src >> ship_container_size;

    std::cout<< num_rows << std::endl;
    std::cout<< num_cols << std::endl;

    for(int i = 0; i < ship_container_size; ++i) {
        char ship_name;
        int ship_length;
        src >> ship_name;
        src >> ship_length;

        BattleShip::Ships new_ship(ship_name, ship_length);

        ship_container.push_back(new_ship);
        std::cout<< "Ship name: " << ship_name << std::endl;
        std::cout<< "Ship length: " << ship_length << std::endl;

    }

}

