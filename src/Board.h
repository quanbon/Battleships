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
        Board(int num_row, int num_col);

        int get_num_rows() const;
        int get_num_cols() const;


        void display_board();

        void place_ship(int col_pos, int row_pos, int ship_size);

    private:
        //Code from Google Drive
        std::vector<std::string> boardContents;
        const int num_row;
        const int num_col;




    };
}



#endif //BATTLESHIPS_BOARD_H
