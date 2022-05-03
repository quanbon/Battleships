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
        Game();

        void configure_game(std::ifstream& configuration_file, int &board_num_rows, int &board_num_cols, std::vector<BattleShip::Ships>& ship_container);

        void setup_game();
    private:
        std::vector<std::unique_ptr<Player>> players;
        int board_num_row;
        int board_num_col;

        int playerTurn;

    };
}



#endif //BATTLESHIPS_GAME_H
