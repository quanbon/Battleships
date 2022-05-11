//
// Created by Quan Nguyen on 5/11/22.
//

#include "AI.h"
#include "Random.h"

void BattleShip::AI::get_ship_direction(char ship_name, std::string &ship_orientation) {
    ship_orientation = rand_orientation(rng);
}

void BattleShip::AI::get_ship_placement(char ship_name, int ship_size, int &num1, int &num2) {
    num1 = rand_row_or_col(rng);
    num2 = rand_row_or_col(rng);
}

void BattleShip::AI::set_generator( std::minstd_rand& rand_gen) {
    rand_gen = this->generator;

}
