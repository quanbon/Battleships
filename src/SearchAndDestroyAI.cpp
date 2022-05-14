//
// Created by Quan Nguyen on 5/12/22.
//

#include "SearchAndDestroyAI.h"
#include "Random.h"
#include <vector>



void BattleShip::SearchAndDestroyAI::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    if(successful_hits_vector.size() > 0) {
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
}

void BattleShip::SearchAndDestroyAI::hunt_mode_activated(int &row, int &col, Board enemy_board) {
    auto element = successful_hits_vector.front();
    int success_row_pos = element.first;
    int success_col_pos = element.second;

    while(true) {
        if (can_shoot_left(enemy_board, success_col_pos, success_row_pos)) {
            row = success_row_pos;
            col = success_col_pos - 1;
            break;
        }
        if (can_shoot_up(enemy_board, success_col_pos, success_row_pos)) {
            row = success_row_pos + 1;
            col = success_col_pos;
            break;
        }
        if (can_shoot_right(enemy_board, success_col_pos, success_row_pos)) {
            row = success_row_pos;
            col = success_col_pos + 1;
            break;
        }
        if (can_shoot_down(enemy_board, success_col_pos, success_row_pos)) {
            row = success_row_pos -1 ;
            col = success_col_pos;
            successful_hits_vector.erase(successful_hits_vector.begin());
            break;
        }
    }
}

bool BattleShip::SearchAndDestroyAI::can_shoot_left(Board enemy_board, int row_pos, int col_pos) {
    return enemy_board.bounds_and_empty_spot_check(row_pos, col_pos-1);
}

bool BattleShip::SearchAndDestroyAI::can_shoot_up(BattleShip::Board enemy_board, int row_pos, int col_pos) {
    return enemy_board.bounds_and_empty_spot_check(row_pos+1, col_pos);
}

bool BattleShip::SearchAndDestroyAI::can_shoot_right(BattleShip::Board enemy_board, int row_pos, int col_pos) {
    return enemy_board.bounds_and_empty_spot_check(row_pos, col_pos+1);
}

bool BattleShip::SearchAndDestroyAI::can_shoot_down(BattleShip::Board enemy_board, int row_pos, int col_pos) {
    return enemy_board.bounds_and_empty_spot_check(row_pos-1, col_pos);
}



