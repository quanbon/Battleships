//
// Created by Quan Nguyen on 4/29/22.
//

#include "Game.h"
#include "file_reader.h"
#include <fstream>

BattleShip::Game::Game() {

}

void BattleShip::Game::configure_game(std::ifstream& src) {
    int ship_container_size;
    src >> this->board_num_col;
    src >> this->board_num_row;
    src >> ship_container_size;

    for(int i = 0; i < ship_container_size; ++i) {
        char ship_name;
        int ship_length;
        src >> ship_name;
        src >> ship_length;

        BattleShip::Ships new_ship(ship_name, ship_length);

        ship_container.push_back(new_ship);



    }
}



void BattleShip::Game::setup_game() {
    const int num_players = 2;
    for(int i = 0; i < num_players; ++i) {
        std::unique_ptr<Player> player;
        //player->set_name("Some name");
        //player->set_board(this->board_num_row, this->board_num_row);
        //player->set_ships(this->ship_container);

    }


}


