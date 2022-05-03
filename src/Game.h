//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include <vector>
#include "Players.h"

namespace BattleShip {
    class Game {
    public:
        void config_game();


    private:
        std::vector<std::unique_ptr<Player>> players;
        int playerTurn;

    };
}



#endif //BATTLESHIPS_GAME_H
