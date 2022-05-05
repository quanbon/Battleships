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

        void set_name(int player_num);
        void set_board(int row, int col);
        void set_ships(std::vector<BattleShip::Ships>& ship_vector);

        std::string get_name();
        void display_placement_board();
        void display_firing_board();
        void display_both_game_boards(std::string player_name);
        void place_ship(int row_pos, int col_pos, int ship_size, char ship_name, std::string orientation);
        bool valid_placement(int row_pos, int col_pos, int ship_size, std::string orientation_choice);

        Board get_placement_board();


    private:
        std::string name;
        Board placement_board;
        Board firing_board;
        std::vector<BattleShip::Ships> player_ships;


    };
}



#endif //BATTLESHIPS_PLAYERS_H
