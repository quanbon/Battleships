//
// Created by harle on 5/10/2022.
//

#ifndef BATTLESHIP_AI_H
#define BATTLESHIP_AI_H
#include "Players.h"
#include <random>

namespace BattleShip {
    class AI : public Player {
    public:
        void get_ship_direction(char ship_name, std::string& ship_orientation) override;
        void get_ship_placement(char ship_name, int ship_size, int &row, int &col, std::string &ship_orientation) override;
        static void set_generator(const int& seed);

    private:
        static std::mt19937 rng;

    };
}

#endif //BATTLESHIP_AI_H
