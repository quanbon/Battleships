//
// Created by Quan Nguyen on 4/29/22.
//

#include "Game.h"
#include "file_reader.h"
#include <fstream>

BattleShip::Game::Game() {

}

void BattleShip::Game::configure_game(std::ifstream& configuration_file, int &board_num_rows, int &board_num_cols, std::vector<BattleShip::Ships>& ship_container) {
    read_config_file(configuration_file, board_num_rows, board_num_cols, ship_container);

}

void BattleShip::Game::setup_game() {
    const int num_players = 2;
    for(int i = 0; i < num_players; ++i) {
        std::unique_ptr<Player> player;

        player->set_name("Some name");




    }


}
