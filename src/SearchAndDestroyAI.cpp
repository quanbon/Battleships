//
// Created by Quan Nguyen on 5/12/22.
//

#include "SearchAndDestroyAI.h"
#include "Random.h"
#include <vector>
#include <algorithm>
#include <iostream>



void BattleShip::SearchAndDestroyAI::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    if(destroy_positions_to_shoot.size() > 0) {
        destroy_mode_activated(row_pos, col_pos, enemy_board);
    } else {
        RandomAI::get_firing_coords(row_pos, col_pos, row_size, col_size, enemy_board);
    }
}

void BattleShip::SearchAndDestroyAI::successful_hit(int &row_pos, int &col_pos) {
    std::pair<int, int> success_spot {row_pos, col_pos};
    successful_hits_vector.push_back(success_spot);

    std::pair<int, int> left_spot {row_pos, col_pos - 1};
    std::pair<int, int> top_spot {row_pos - 1, col_pos};
    std::pair<int, int> right_spot {row_pos, col_pos + 1};
    std::pair<int, int> bottom_spot {row_pos + 1, col_pos};

    destroy_positions_to_shoot.push_back(left_spot);
    destroy_positions_to_shoot.push_back(top_spot);
    destroy_positions_to_shoot.push_back(right_spot);
    destroy_positions_to_shoot.push_back(bottom_spot);

}

void BattleShip::SearchAndDestroyAI::destroy_mode_activated(int &row, int &col, Board enemy_board) {
    while(true) {
        if(enemy_board.bounds_and_empty_spot_check(destroy_positions_to_shoot[0].first, destroy_positions_to_shoot[0].second)){
            row = destroy_positions_to_shoot[0].first;
            col = destroy_positions_to_shoot[0].second;
            auto item = destroy_positions_to_shoot[0];
            coordinate_vector.erase(std::remove(coordinate_vector.begin(), coordinate_vector.end(), item), coordinate_vector.end());
            destroy_positions_to_shoot.erase(destroy_positions_to_shoot.begin());
            return;
        }
        else {
            destroy_positions_to_shoot.erase(destroy_positions_to_shoot.begin());
        }
    }
}






