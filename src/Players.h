//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_PLAYERS_H
#define BATTLESHIPS_PLAYERS_H
#include <vector>
#include "Board.h"
#include "Ships.h"

namespace BattleShip {
    class Player {
    public:
        Player();

        void set_name(const std::string& player_name);
        void set_board(int row, int col);
        void set_ships(std::vector<BattleShip::Ships>& ship_vector);


    private:
        std::string name;
        Board placement_board;
        Board firing_board;
        std::vector<BattleShip::Ships> player_ships;


    };
}



#endif //BATTLESHIPS_PLAYERS_H
