//
// Created by Quan Nguyen on 4/29/22.
//

#include "Players.h"
#include "Input_Validation.h"


BattleShip::Player::Player() {


}



void BattleShip::Player::set_name(int player_num) {
    this->name = get_player_name(player_num);

}

void BattleShip::Player::set_board(int row, int col) {
    this->placement_board = Board(row, col);
    this->firing_board = Board(row, col);


}

void BattleShip::Player::set_ships(std::vector<BattleShip::Ships>& ship_vector) {
    this->player_ships = ship_vector;

}

void BattleShip::Player::display_placement_board() {
    this->placement_board.display_board();

}

std::string BattleShip::Player::get_name() {
    return this->name;

}

BattleShip::Board BattleShip::Player::get_placement_board() {
    return this->placement_board;
}

void BattleShip::Player::place_ship(int row_pos, int col_pos, int ship_size, char ship_name, std::string orientation) {
    this->placement_board.place_ship(row_pos, col_pos, ship_size, ship_name, orientation);

}

bool BattleShip::Player::valid_placement(int row_pos, int col_pos, int ship_size, std::string orientation_choice) {
    return this->placement_board.in_bounds_check(row_pos, col_pos, ship_size, orientation_choice);
}




