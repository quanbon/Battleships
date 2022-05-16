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
            this->boardContents.at(row_pos).at(col_pos+i) = ship_name;
        }
    }

    if(orientation == "V" or orientation == "v") {
        for(int i = 0; i < ship_size; ++i) {
            this->boardContents.at(row_pos+i).at(col_pos) = ship_name;
        }
    }

}

bool BattleShip::Board::in_bounds_vertical(int row_pos, int ship_size) const {
    return row_pos > -1 and (row_pos + ship_size) <= this->num_row;
}

bool BattleShip::Board::in_bounds_horizontal(int col_pos, int ship_size) const {
    return col_pos > -1 and (col_pos + ship_size) <= this->num_col;
}


bool BattleShip::Board::overlap_vertical_check(int row_pos, int col_pos, int ship_size) {
    for(int i = 0; i < ship_size; ++i) {
        if(this->boardContents.at(row_pos+i).at(col_pos) != '*') {
            return false;
        }
    }
    return true;
}

bool BattleShip::Board::overlap_horizontal_check(int row_pos, int col_pos, int ship_size) {
    for(int i = 0; i < ship_size; ++i) {
        if(this->boardContents.at(row_pos).at(col_pos+i) != '*') {
            return false;
        }
    }
    return true;
}



bool BattleShip::Board::in_bounds_check(int row_pos, int col_pos, int ship_size, std::string orientation_choice) {
    if (orientation_choice == "H" or orientation_choice == "h") {
        return in_bounds_horizontal(col_pos, ship_size) and is_between_row(row_pos) and overlap_horizontal_check(row_pos, col_pos, ship_size);
    }
    if (orientation_choice == "V" or orientation_choice == "v") {
        return in_bounds_vertical(row_pos, ship_size) and is_between_col(col_pos) and overlap_vertical_check(row_pos, col_pos, ship_size);
    }
    return false;
}
// this could bug out
bool BattleShip::Board::is_between_row(int pos) {
    return pos > -1 and pos < this->num_row;
}

bool BattleShip::Board::is_between_col(int pos) {
    return pos  > -1 and pos < this->num_col;
}

bool BattleShip::Board::is_between_row_ai(int pos) {
    return pos > -1 and pos < this->num_row;
}

bool BattleShip::Board::is_between_col_ai(int pos) {
    return pos > -1 and pos < this->num_col;
}


bool BattleShip::Board::check_for_hit(int row_choice, int col_choice, char& ship_name) {
    if(this->boardContents.at(row_choice).at(col_choice) == '*' or
       this->boardContents.at(row_choice).at(col_choice) == 'X' or
       this->boardContents.at(row_choice).at(col_choice) == 'O' ) {
        return false;
    } else {
        ship_name = this->boardContents.at(row_choice).at(col_choice);
    }
    return true;
}

void BattleShip::Board::ship_was_hit(int row_choice, int col_choice) {
    this->boardContents.at(row_choice).at(col_choice) = 'X';

}

void BattleShip::Board::ship_was_missed(int row_choice, int col_choice) {
    this->boardContents.at(row_choice).at(col_choice) = 'O';

}

bool BattleShip::Board::check_for_blank_char(int row_choice, int col_choice) {
    if(this->boardContents.at(row_choice).at(col_choice) == '*') {
        return true;
    } else {
        return false;
    }
}

bool BattleShip::Board::bounds_and_empty_spot_check(int row_pos, int col_pos) {
    return is_between_row_ai(row_pos) and
    is_between_col_ai(col_pos) and
    search_and_destroy_spot_check(row_pos, col_pos);
}

bool BattleShip::Board::search_and_destroy_spot_check(int row_pos, int col_pos) {
    if(this->boardContents.at(row_pos).at(col_pos) != 'X' and this->boardContents.at(row_pos).at(col_pos) != 'O') {
        return true;
    } else {
        return false;
    }
}

void BattleShip::Board::hacks_for_cheating_ai(int &row_pos, int &col_pos, std::vector<std::pair<int, int>>& hacks) {
    for(int i = 0; i < get_num_cols(); ++i) {
        for(int j = 0; j < get_num_rows(); ++j) {
            if(boardContents.at(i).at(j) != '*') {
                std::pair<int, int> cheating_spots {i, j};
                hacks.push_back(cheating_spots);
            }
        }
    }
}














