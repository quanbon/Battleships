//
// Created by Quan Nguyen on 5/11/22.
//

#include "AI.h"
#include "RandomAI.h"
#include "Random.h"
std::vector<std::pair<int, int>> BattleShip::RandomAI::coordinate_vector;

void BattleShip::RandomAI::get_firing_coords(int &num1, int &num2, int row_size, int col_size) {
    int element = get_random_element(rng, coordinate_vector.size() -1);
    num1 = coordinate_vector[element].first;
    num2 = coordinate_vector[element].second;
    coordinate_vector.erase(coordinate_vector.begin() + element);
}

void BattleShip::RandomAI::set_coord_vector(std::vector<std::pair<int, int>>& coord_vector) {
    coordinate_vector = coord_vector;
}
