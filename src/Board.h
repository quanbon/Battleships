//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_BOARD_H
#define BATTLESHIPS_BOARD_H
#include <vector>
#include <string>

namespace BattleShip {
    class Board {
    public:
        Board();
        Board(int num_row, int num_col);

        int get_num_rows() const;
        int get_num_cols() const;
        void display_board();
        void place_ship(int col_pos, int row_pos, int ship_size, char ship_name, std::string orientation);
        bool is_between(int pos);
        bool in_bounds_vertical(int row_pos, int ship_size) const;
        bool in_bounds_horizontal(int col_pos, int ship_size) const;
        bool in_bounds_check(int row_pos, int col_pos, int ship_size, std::string orientation_choice);
        bool overlap_vertical_check(int row_pos, int col_pos, int ship_size);
        bool overlap_horizontal_check(int row_pos, int col_pos, int ship_size);
        bool check_for_hit(int row_choice, int col_choice, char& ship_name);
        void ship_was_hit(int row_choice, int col_choice);
        void ship_was_missed(int row_choice, int col_choice);
        bool check_for_blank_char(int row_choice, int col_choice);

    private:
        //Code from Google Drive
        std::vector<std::string> boardContents;
        int num_row;
        int num_col;
    };
}



#endif //BATTLESHIPS_BOARD_H
