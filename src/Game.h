//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include <vector>
#include <map>
#include <memory>
#include "Players.h"

namespace BattleShip {
    class Game {
    public:
        Game();

        std::vector<BattleShip::Ships> sort_ships(std::vector<BattleShip::Ships> ship_container);
        void configure_game(std::ifstream& src);
        void set_player_board_and_ship();
        BattleShip::Player& get_current_player();
        BattleShip::Player& get_opposing_player();
        void fire_shot();
        void change_player_turn();
        void setup_game();
        void play_game();
        void check_for_hit(int row_choice, int col_choice, char& ship_hit);
        bool is_game_over();
        void check_for_ship_destroyed(char& ship_name);
        void get_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size);
        void check_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size);

    private:
        std::vector<std::unique_ptr<Player>> players;
        std::vector<BattleShip::Ships> ship_container;
        std::map<char, int> ship_map;
        int board_num_row;
        int board_num_col;
        int playerTurn;

    };
}



#endif //BATTLESHIPS_GAME_H
