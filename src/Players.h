//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_PLAYERS_H
#define BATTLESHIPS_PLAYERS_H
#include <vector>
#include <map>
#include "Board.h"
#include "Ships.h"
#include "Input_Validation.h"


namespace BattleShip {
    class Player {
    public:
        Player();

        virtual void set_name(int player_num);
        void set_board(int row, int col);
        void set_ships(std::map<char, int >& ship_map);

        int get_board_row();
        int get_board_col();

        std::string get_name();
        virtual void display_placement_board();
        void display_firing_board();
        void display_both_game_boards(std::string player_name);

        virtual void get_ship_direction(char ship_name, std::string& ship_orientation);
        virtual void get_ship_placement(char ship_name, int ship_size, int &row, int &col, std::string &ship_orientation);
        virtual void place_ship(int row_pos, int col_pos, int ship_size, char ship_name, std::string orientation);

        virtual void get_firing_coords(int &num1, int &num2, int row_size, int col_size);

        bool valid_placement(int row_pos, int col_pos, int ship_size, std::string orientation_choice);
        bool check_for_hit(int row_choice, int col_choice, char& ship_name);
        bool check_for_blank_char(int row_choice, int col_choice);

        void ship_was_hit_on_place_board(int row_choice, int col_choice);
        void ship_was_hit_on_firing_board(int row_choice, int col_choice);
        void ship_was_miss_on_place_board(int row_choice, int col_choice);
        void ship_was_miss_on_firing_board(int row_choice, int col_choice);

        bool check_for_empty_map();
        void decrement_ship(char ship_name);
        bool check_for_ship_destroyed(char ship_name);
        void remove_ship(char ship_name);

    protected:
        std::string name;
        Board placement_board;
        Board firing_board;
        std::map<char, int> player_ships;


    };
}



#endif //BATTLESHIPS_PLAYERS_H
