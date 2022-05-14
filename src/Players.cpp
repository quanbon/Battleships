//
// Created by Quan Nguyen on 4/29/22.
//

#include "Players.h"
#include "Input_Validation.h"
#include <iostream>


BattleShip::Player::Player() {


}
void BattleShip::Player::set_name(int player_num) {
    this->name = get_player_name(player_num);

}

void BattleShip::Player::set_board(int row, int col) {
    this->placement_board = Board(row, col);
    this->firing_board = Board(row, col);

}

void BattleShip::Player::set_ships(std::map<char, int >& ship_map) {
    this->player_ships = ship_map;

}

void BattleShip::Player::display_placement_board() {
    this->placement_board.display_board();

}

void BattleShip::Player::display_firing_board() {
    this->firing_board.display_board();

}

void BattleShip::Player::display_both_game_boards(std::string player_name) {
    std::cout << player_name << "'s Firing Board" << std::endl;
    this->firing_board.display_board();

    std::cout << "\n\n";
    std::cout << player_name << "'s Placement Board" << std::endl;
    this->placement_board.display_board();

}


std::string BattleShip::Player::get_name() {
    return this->name;
}

void BattleShip::Player::get_ship_direction(char ship_name, std::string& ship_orientation) {
    get_ship_direction_choice(this->name, ship_name, ship_orientation);
}

void BattleShip::Player::get_ship_placement(char ship_name, int ship_size, int &row, int &col, std::string &ship_orientation) {
    get_two_ints(this->name, ship_name, ship_size, row, col);
}

void BattleShip::Player::place_ship(int row_pos, int col_pos, int ship_size, char ship_name, std::string orientation) {
    this->placement_board.place_ship(row_pos, col_pos, ship_size, ship_name, orientation);
}

bool BattleShip::Player::valid_placement(int row_pos, int col_pos, int ship_size, std::string orientation_choice) {
    return this->placement_board.in_bounds_check(row_pos, col_pos, ship_size, orientation_choice);
}

bool BattleShip::Player::check_for_hit(int row_choice, int col_choice, char& ship_name) {
    return this->placement_board.check_for_hit(row_choice, col_choice, ship_name);
}

void BattleShip::Player::decrement_ship(char ship_name) {
    this->player_ships[ship_name]--;

}

void BattleShip::Player::ship_was_hit_on_place_board(int row_choice, int col_choice) {
    this->placement_board.ship_was_hit(row_choice, col_choice);

}

void BattleShip::Player::ship_was_hit_on_firing_board(int row_choice, int col_choice) {
    this->firing_board.ship_was_hit(row_choice, col_choice);

}

void BattleShip::Player::ship_was_miss_on_place_board(int row_choice, int col_choice) {
    this->placement_board.ship_was_missed(row_choice, col_choice);
}

void BattleShip::Player::ship_was_miss_on_firing_board(int row_choice, int col_choice) {
    this->firing_board.ship_was_missed(row_choice, col_choice);

}

bool BattleShip::Player::check_for_empty_map() {
    return this->player_ships.empty();
}

bool BattleShip::Player::check_for_ship_destroyed(char ship_name) {
    if (this->player_ships[ship_name] == 0) {
        return true;
    } else { return false; }
}

void BattleShip::Player::remove_ship(char ship_name) {
    this->player_ships.erase(ship_name);
}

bool BattleShip::Player::check_for_blank_char(int row_choice, int col_choice) {
    if(this->firing_board.check_for_blank_char(row_choice, col_choice)) {
        return true;
    } else {
        return false;
    }
}

int BattleShip::Player::get_board_row() {
    return this->placement_board.get_num_rows();
}

int BattleShip::Player::get_board_col() {
    return this->placement_board.get_num_cols();
}

void BattleShip::Player::get_firing_coords(int &row_pos, int &col_pos, int row_size, int col_size, Board enemy_board) {
    BattleShip::get_firing_pos(this->name, row_pos, col_pos, row_size, col_size);

}

void BattleShip::Player::set_coord_vector() {
    std::vector<std::pair<int, int>> coords;
    for(int i = 0; i < this->placement_board.get_num_rows(); i++) {
        for(int j = 0; j < this->placement_board.get_num_cols(); j++) {
            std::pair<int, int> new_spot {i, j};
            coords.push_back(new_spot);
        }
    }
    this->coordinate_vector = coords;
}

BattleShip::Board BattleShip::Player::get_placement_board() {
    return this->placement_board;
}

void BattleShip::Player::successful_hit(int &row_pos, int &col_pos) {
    return;
}

