//
// Created by Quan Nguyen on 4/29/22.
//

#include "Players.h"


BattleShip::Player::Player() {
//    this->placement_board = Board(1, 1);
//    this->firing_board = Board(1, 1);

}

void BattleShip::Player::set_name(const std::string &player_name) {
    this->name = player_name;

}

//void BattleShip::Player::set_board(int row, int col) {
//    this->placement_board = Board(row, col);
//    this->firing_board = Board(row, col);
//
//
//}

void BattleShip::Player::set_ships(std::vector<BattleShip::Ships>& ship_vector) {
    this->player_ships = ship_vector;

}


