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
        void get_firing_coords(int &num1, int &num2, int row_size, int col_size) override;
        static void set_coord_vector(std::vector<std::pair<int, int>>& coord_vector);

    private:
        static std::vector<std::pair<int, int>> coordinate_vector;
    };
}

#endif //BATTLESHIP_RANDOMAI_H
