//
// Created by Quan Nguyen on 5/11/22.
//


#include "AI.h"
#include <iostream>
#include "Random.h"
#include <string>

std::mt19937 BattleShip::AI::rng;


void BattleShip::AI::get_ship_direction(char ship_name, std::string &ship_orientation) {
    ship_orientation = rand_orientation(rng);
}

void BattleShip::AI::get_ship_placement(char ship_name, int ship_size, int &row, int &col, std::string &ship_orientation) {
    int board_row = this->get_board_row();
    int board_col = this->get_board_col();
    if(ship_orientation == "H") {
        row = rand_row_or_col(rng, board_row - 1);
        col = rand_row_or_col(rng, board_col - ship_size);
    }
    else if (ship_orientation == "V") {
        row = rand_row_or_col(rng, board_row - ship_size);
        col = rand_row_or_col(rng, board_col - 1);
    }
}

void BattleShip::AI::set_generator(const int& seed) {
    rng.seed(seed);
}

void BattleShip::AI::set_name(int player_num) {
    std::string name =  "AI ";
    name.append(std::to_string(player_num+1));
    this->name = name;


}

void BattleShip::AI::display_placement_board() {
    std::cout << this->name << "'s Board" << std::endl;
    this->placement_board.display_board();
}
