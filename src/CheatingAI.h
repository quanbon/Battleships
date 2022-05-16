//
// Created by harle on 5/10/2022.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H

#include "AI.h"

namespace BattleShip {
    class CheatingAI : public AI {
    public:
        void get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) override;

    private:
        std::vector<std::pair<int, int>> cheat_positions;
    };
}

#endif //BATTLESHIP_CHEATINGAI_H
