//
// Created by Quan Nguyen on 4/29/22.
//

#include "Game.h"
#include "Board.h"
#include "Input_Validation.h"
#include "file_reader.h"
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

BattleShip::Game::Game() {
}

std::vector<BattleShip::Ships> sort_ships (std::vector<BattleShip::Ships> ship_container, int ship_quantity) {
    std::vector<char> assorted_container;
    std::vector<BattleShip::Ships> new_ship_container;

    for (int i = 0; i < ship_quantity; i++) {
        char ship_name = ship_container.at(i).get_ship_name();
        assorted_container.push_back(ship_name);
    }

    std::sort(assorted_container.begin(), assorted_container.end(), [](char& a, char& b) {return tolower(a) < tolower(b); });

    for (int i = 0; i < ship_quantity; i++) {
        for (int j = 0; j < ship_quantity; j++) {
            char actual_ship_name = ship_container.at(j).get_ship_name();
            if (assorted_container.at(i) == actual_ship_name) {
                new_ship_container.push_back(ship_container.at(j));
            }
        }
    }
    return new_ship_container;
}



void BattleShip::Game::configure_game(std::ifstream& src) {
    int ship_container_size;
    src >> this->board_num_row;
    src >> this->board_num_col;
    src >> ship_container_size;

    this->playerTurn = 0;

    for(int i = 0; i < ship_container_size; ++i) {
        char ship_name;
        int ship_length;
        src >> ship_name;
        src >> ship_length;

        ship_map[ship_name] = ship_length;
        BattleShip::Ships new_ship(ship_name, ship_length);
        ship_container.push_back(new_ship);
    }

    ship_container = ::sort_ships(ship_container, ship_container_size);

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

bool BattleShip::Game::is_game_over () {
    if (get_opposing_player().check_for_empty_map()) {
        std::cout << std::endl;
        std::cout << get_current_player().get_name() << " won the game!" << std::endl;
        return true;
    } else { return false; }
}

void BattleShip::Game::play_game() {
    while(!is_game_over()) {
        int row_choice, col_choice;
        char ship_hit;

        get_current_player().display_both_game_boards(get_current_player().get_name());
        check_firing_pos(get_current_player().get_name(), row_choice, col_choice, this->board_num_row, this->board_num_col);
        check_for_hit(row_choice, col_choice, ship_hit);
        if (is_game_over()) {
            break;
        }
        change_player_turn();
    }
}

BattleShip::Player& BattleShip::Game::get_current_player() {
    return *this->players.at(playerTurn);
}

BattleShip::Player &BattleShip::Game::get_opposing_player() {
    if(playerTurn == 0) {
        return *players.back();
    } else {
        return *players.front();
    }
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
        player->set_board(this->board_num_row, this->board_num_col);
        player->set_ships(this->ship_map);
        this->players.push_back(std::move(player));
    }
}


void BattleShip::Game::check_for_hit(int row_choice, int col_choice, char& ship_hit) {
    if(get_opposing_player().check_for_hit(row_choice, col_choice, ship_hit)) {
        get_opposing_player().decrement_ship(ship_hit);
        get_opposing_player().ship_was_hit_on_place_board(row_choice, col_choice);
        get_current_player().ship_was_hit_on_firing_board(row_choice, col_choice);

        std::string cur_player = get_current_player().get_name();
        std::string opp_player = get_opposing_player().get_name();
        get_current_player().display_both_game_boards(get_current_player().get_name());
        std::cout << cur_player << " hit " << opp_player << "'s " << ship_hit <<"!" << std::endl;
        check_for_ship_destroyed(ship_hit);
    } else {
        get_current_player().ship_was_miss_on_firing_board(row_choice, col_choice);
        get_opposing_player().ship_was_miss_on_place_board(row_choice, col_choice);
        get_current_player().display_both_game_boards(get_current_player().get_name());
        std::cout<< "Missed." << std::endl;
    }

}

void BattleShip::Game::check_for_ship_destroyed(char& ship_name) {
    if (get_opposing_player().check_for_ship_destroyed(ship_name)) {
        get_opposing_player().remove_ship(ship_name);
        std::cout << get_current_player().get_name() << " destroyed " <<
        get_opposing_player().get_name() << "'s " << ship_name << "!" << std::endl;
    }
}

void BattleShip::Game::get_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size) {
    std::string line;
    while (true) {
        std::cout << player_name << ", where would you like to fire?" << std::endl;
        std::cout<< "Enter your attack coordinate in the form row col: ";
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        line2parse >> num1 >> num2;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;


            if (not line2parse) {//if there is nothing left we will fail to read i
                return;
            }
        }
    }
}

void BattleShip::Game::check_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size) {
    while(true) {
        get_firing_pos(player_name, num1, num2, row_size, col_size);
        if(!is_between(num1, num2, row_size, col_size)) {
            get_current_player().display_both_game_boards(get_current_player().get_name());
            continue;
        } else if(!get_current_player().check_for_blank_char(num1, num2)) {
            get_current_player().display_both_game_boards(get_current_player().get_name());
            continue;
        } else {
            break;
        }
    }
}