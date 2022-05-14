//
// Created by harle on 5/10/2022.
//

#ifndef BATTLESHIP_SEARCHANDDESTROYAI_H
#define BATTLESHIP_SEARCHANDDESTROYAI_H

#include "RandomAI.h"

namespace BattleShip {
    class SearchAndDestroyAI : public RandomAI {
    public:
        void get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) override;
        void successful_hit(int &row_pos, int &col_pos) override;
        void hunt_mode_activated(int &row, int &col, Board enemy_board);
        bool can_shoot_left(Board enemy_board, int row_pos, int col_pos);
        bool can_shoot_up(Board enemy_board, int row_pos, int col_pos);
        bool can_shoot_right(Board enemy_board, int row_pos, int col_pos);
        bool can_shoot_down(Board enemy_board, int row_pos, int col_pos);


    private:
        std::vector<std::pair<int, int>> successful_hits_vector;
    };
}

#endif //BATTLESHIP_SEARCHANDDESTROYAI_H
