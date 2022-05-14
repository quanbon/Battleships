//
// Created by Quan Nguyen on 5/11/22.
//

#include "AI.h"
#include "RandomAI.h"
#include "Random.h"
//std::vector<std::pair<int, int>> BattleShip::RandomAI::coordinate_vector;

void BattleShip::RandomAI::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    int element = get_random_element(rng, coordinate_vector.size() -1);
    row_pos = coordinate_vector[element].first;
    col_pos = coordinate_vector[element].second;
    coordinate_vector.erase(coordinate_vector.begin() + element);
}


