//
// Created by Quan Nguyen on 4/29/22.
//

#include "Board.h"
#include <iostream>

BattleShip::Board::Board() {

}

//Code from Google Drive
BattleShip::Board::Board(int num_row, int num_col) : boardContents(num_row, std::string(num_col, '*')),
                                                      num_row(num_row), num_col(num_col){
//Board Contents is a vector of strings which is initialized with the nun_row = num_of_strings, with each string having num_cols of *'s
}


int BattleShip::Board::get_num_rows() const {
    return this->num_row;
}

int BattleShip::Board::get_num_cols() const {
    return this->num_col;
}

//Code from Google Drive -- Loops through a vector of strings
void BattleShip::Board::display_board() {
    //Prints out the col header
    std::cout << "  ";
    for(int i = 0; i < get_num_cols(); ++i) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
    int num_row = 0;
    for(const auto& row: boardContents) {
        std::cout << num_row << ' '; //Prints the row header

        //Here row represents each string and piece are the individual chars
        for(const auto& piece : row) {
            std::cout << piece << ' ';
        }
        std::cout << std::endl;
        ++num_row;
    }
}

void BattleShip::Board::place_ship(int row_pos, int col_pos, int ship_size, char ship_name, std::string orientation)  {
    if(orientation == "H" or orientation == "h") {
        for(int i = 0; i < ship_size; ++i) {
            this->boardContents.at(col_pos+i).at(row_pos) = ship_name;
        }
    }

    if(orientation == "V" or orientation == "v") {
        for(int i = 0; i < ship_size; ++i) {
            this->boardContents.at(col_pos).at(row_pos+i) = ship_name;
        }
    }

}

bool BattleShip::Board::in_bounds_vertical(int row_pos, int ship_size) const {
    return row_pos > -1 and (row_pos + ship_size) <= this->num_row; //check if the starting position is in bounds
}

bool BattleShip::Board::in_bounds_horizontal(int col_pos, int ship_size) const {
    return col_pos > -1 and (col_pos + ship_size) <= this->num_col;
}

bool BattleShip::Board::in_bounds_check(int row_pos, int col_pos, int ship_size, std::string orientation_choice) {
    if (orientation_choice == "H" or orientation_choice == "h") {
        return in_bounds_horizontal(col_pos, ship_size);
    }
    if (orientation_choice == "V" or orientation_choice == "v") {
        return in_bounds_vertical(row_pos, ship_size);
    }
}

//bool BattleShip::Board::overlap_check_vertical(int row_pos, int col_pos, int ship_size) const {
//    for(int i = 0; i < ship_size; i++) {
//        boardContents.at(col_pos).at(row_pos+i) != '*';
//    }
//}







