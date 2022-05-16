//
// Created by Quan Nguyen on 5/15/22.
//

#include "CheatingAI.h"
#include "Board.h"

void
BattleShip::CheatingAI::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    if(cheat_positions.size() < 1) {
        enemy_board.hacks_for_cheating_ai(row_pos, col_pos, cheat_positions);
    }
    row_pos = cheat_positions[0].first;
    col_pos = cheat_positions[0].second;
    cheat_positions.erase(cheat_positions.begin());
}

