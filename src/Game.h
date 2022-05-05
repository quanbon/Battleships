//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include <vector>
#include <memory>
#include "Players.h"

namespace BattleShip {
    class Game {
    public:
        Game();

        void configure_game(std::ifstream& src);
        void set_player_board_and_ship();
        BattleShip::Player& get_current_player();
        void change_player_turn();
        void setup_game();
        void play_game();
    private:
        std::vector<std::unique_ptr<Player>> players;
        std::vector<BattleShip::Ships> ship_container;
        int board_num_row;
        int board_num_col;
        int playerTurn;

    };
}



#endif //BATTLESHIPS_GAME_H
