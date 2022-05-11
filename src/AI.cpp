//
// Created by Quan Nguyen on 5/11/22.
//


#include "AI.h"
#include "Random.h"
#include "Board.h"

std::mt19937 BattleShip::AI::rng;


void BattleShip::AI::get_ship_direction(char ship_name, std::string &ship_orientation) {
    ship_orientation = rand_orientation(rng);
}

void BattleShip::AI::get_ship_placement(char ship_name, int ship_size, int &row, int &col) {
    int board_row = this->get_board_row();
    int board_col = this->get_board_col();

    row = rand_row_or_col(rng, board_row);
    col = rand_row_or_col(rng, board_col);
}

void BattleShip::AI::set_generator(const int& seed) {
    rng.seed(seed);
}
