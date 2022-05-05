//
// Created by Quan Nguyen on 4/29/22.
//

#include "Game.h"
#include "Board.h"
#include "Input_Validation.h"
#include "file_reader.h"
#include <fstream>
#include <iostream>

BattleShip::Game::Game() {

}

void BattleShip::Game::configure_game(std::ifstream& src) {
    int ship_container_size;
    src >> this->board_num_col;
    src >> this->board_num_row;
    src >> ship_container_size;

    this->playerTurn = 0;

    for(int i = 0; i < ship_container_size; ++i) {
        char ship_name;
        int ship_length;
        src >> ship_name;
        src >> ship_length;

        BattleShip::Ships new_ship(ship_name, ship_length);
        ship_container.push_back(new_ship);
    }
    set_player_board_and_ship();

}



void BattleShip::Game::setup_game() {
    for(int i = 0; i < 2; ++i) {
        Player& cur_player = get_current_player();
        cur_player.set_name(playerTurn);

        for (auto ships: ship_container) {
            char ship_name  = ships.get_ship_name();
            int ship_length = ships.get_ship_length();
            std::string orientation_choice;
            int row_choice, col_choice;

            cur_player.display_placement_board();

            while (true) {
                get_ship_direction_choice(cur_player.get_name(), ship_name, orientation_choice);
                get_two_ints(cur_player.get_name(), ship_name, ship_length, row_choice, col_choice);
               if(cur_player.valid_placement(row_choice, col_choice, ship_length, orientation_choice)) {
                   break;
               } else {
                   continue;
               }
            }
            cur_player.place_ship(row_choice, col_choice, ship_length, ship_name, orientation_choice);
        }

        cur_player.display_placement_board();
        change_player_turn();
    }
}

void BattleShip::Game::play_game() {
    Player& cur_player = get_current_player();
    cur_player.display_both_game_boards(cur_player.get_name());

}

BattleShip::Player& BattleShip::Game::get_current_player() {
    return *this->players.at(playerTurn);
}

void BattleShip::Game::change_player_turn() {
    ++playerTurn;
    if (playerTurn == static_cast<int>(players.size())) {
        playerTurn = 0;
    }
}


void BattleShip::Game::set_player_board_and_ship() {
    const int num_players = 2;
    for(int i = 0; i < num_players; ++i) {
        std::unique_ptr<Player> player = std::make_unique<Player>();
        //player->set_name("Some name");
        player->set_board(this->board_num_row, this->board_num_row);
        player->set_ships(this->ship_container);
        this->players.push_back(std::move(player));
    }
}




