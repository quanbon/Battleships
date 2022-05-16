//
// Created by Quan Nguyen on 5/12/22.
//

#include "SearchAndDestroyAI.h"
#include "Random.h"
#include <vector>
#include <iostream>



void BattleShip::SearchAndDestroyAI::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    if(hunt_positions_to_shoot.size() > 0) {
        hunt_mode_activated(row_pos, col_pos, enemy_board);
    } else {
        int element = get_random_element(rng, coordinate_vector.size() -1);
        row_pos = coordinate_vector[element].first;
        col_pos = coordinate_vector[element].second;
        coordinate_vector.erase(coordinate_vector.begin() + element);
    }


}

void BattleShip::SearchAndDestroyAI::successful_hit(int &row_pos, int &col_pos) {
    std::pair<int, int> success_spot {row_pos, col_pos};
    successful_hits_vector.push_back(success_spot);

    std::pair<int, int> left_spot {row_pos, col_pos - 1};
    std::pair<int, int> top_spot {row_pos - 1, col_pos};
    std::pair<int, int> right_spot {row_pos, col_pos + 1};
    std::pair<int, int> bottom_spot {row_pos + 1, col_pos};

    hunt_positions_to_shoot.push_back(left_spot);
    hunt_positions_to_shoot.push_back(top_spot);
    hunt_positions_to_shoot.push_back(right_spot);
    hunt_positions_to_shoot.push_back(bottom_spot);
}

void BattleShip::SearchAndDestroyAI::hunt_mode_activated(int &row, int &col, Board enemy_board) {
//    for (auto Iter = hunt_positions_to_shoot.begin(); Iter != hunt_positions_to_shoot.end(); ++Iter) {
//        if(enemy_board.bounds_and_empty_spot_check(Iter->first, Iter->second)) {
//            row = Iter->first;
//            col = Iter->second;
//            hunt_positions_to_shoot.erase(hunt_positions_to_shoot.begin());
//            break;
//        }
//        else {
//            hunt_positions_to_shoot.erase(hunt_positions_to_shoot.begin());
//        }
//    }
    while(true) {
        if(enemy_board.bounds_and_empty_spot_check(hunt_positions_to_shoot[0].first, hunt_positions_to_shoot[0].second)){
            row = hunt_positions_to_shoot[0].first;
            col = hunt_positions_to_shoot[0].second;
            hunt_positions_to_shoot.erase(hunt_positions_to_shoot.begin());
            return;
        }
        else {
            hunt_positions_to_shoot.erase(hunt_positions_to_shoot.begin());
        }
    }
}






