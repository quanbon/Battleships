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
        void configure_game(std::ifstream& src);
        void add_only_human_players();
        void add_human_and_ai(const int &ai_type);
        void add_ai(const int &ai_type);
        void game_type_input();

        BattleShip::Player& get_current_player();
        BattleShip::Player& get_opposing_player();
        void change_player_turn();

        void setup_game();
        void play_game();
        bool is_game_over();

        void get_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size);
        void check_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size);
        void check_for_hit(int row_choice, int col_choice, char& ship_hit);
        void check_for_ship_destroyed(char& ship_name);

        std::vector<BattleShip::Ships> sort_ships(std::vector<BattleShip::Ships> ship_container);


    private:
        std::vector<std::unique_ptr<Player>> players;
        std::vector<BattleShip::Ships> ship_container;
        std::map<char, int> ship_map;
        int board_num_row;
        int board_num_col;
        int playerTurn;
        int game_type;

    };
}



#endif //BATTLESHIPS_GAME_H
