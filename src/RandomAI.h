//
// Created by harle on 5/10/2022.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H

#include "AI.h"
#include "vector"

namespace BattleShip {
    class RandomAI : public AI {
    public:
        virtual void get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) override;


    protected:
    };
}

#endif //BATTLESHIP_RANDOMAI_H
