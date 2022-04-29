//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_PLAYERS_H
#define BATTLESHIPS_PLAYERS_H
#include <vector>
#include "Board.h"
#include "Ships.h"

namespace BattleShip {
    class Players {
    public:


    private:
        const std::string name;
        BattleShip::Board placement_board;
        BattleShip::Board firing_board;
        std::vector<BattleShip::Ships>;


    };
}



#endif //BATTLESHIPS_PLAYERS_H
