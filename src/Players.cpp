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


