//
// Created by Quan Nguyen on 4/29/22.
//

#include "Board.h"
#include <iostream>


//Code from Google Drive
Battleships::Board::Board(int num_row, int num_col) : boardContents(num_row, std::string(num_col, '*')),
                                                      num_row(num_row), num_col(num_col){
//Board Contents is a vector of strings which is initialized with the nun_row = num_of_strings, with each string having num_cols of *'s
}


int Battleships::Board::get_num_rows() const {
    return this->num_row;
}

int Battleships::Board::get_num_cols() const {
    return this->num_col;
}

//Code from Google Drive -- Loops through a vector of strings
void Battleships::Board::display_board() {
    //Prints out the col header
    std::cout << " ";
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
