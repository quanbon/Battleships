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
#include "Players.h"
#include "AI.h"
#include "Human.h"
#include "CheatingAI.h"
#include "SearchAndDestroyAI.h"
#include "RandomAI.h"


BattleShip::Game::Game() {
}
std::vector<BattleShip::Ships> sort_ships (std::vector<BattleShip::Ships> ship_container, int ship_quantity);
bool is_game_over();


void BattleShip::Game::configure_game(std::ifstream& src, const int& seed) {
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
    Board board(this->board_num_row, this->board_num_col);
    AI::set_generator(seed);
}

void BattleShip::Game::game_type_input() {
    int game_type;
    int ai_type;
    int human_v_human = 1, human_v_ai = 2, ai_v_ai = 3;

    get_game_type(game_type);
    if (game_type == human_v_human) {
        add_only_human_players();
    }
    else if(game_type == human_v_ai) {
        get_ai_type(ai_type);
        add_human_and_ai(ai_type);
    }
    else if(game_type == ai_v_ai) {
        get_ai_type(ai_type);
        add_ai(ai_type);
    }
}

void BattleShip::Game::add_only_human_players() {
    const int num_players = 2;
    for(int i = 0; i < num_players; ++i) {
        std::unique_ptr<Player> player = std::make_unique<Human>();
        player->set_board(this->board_num_row, this->board_num_col);
        player->set_ships(this->ship_map);
        this->players.push_back(std::move(player));
    }
}

void BattleShip::Game::add_human_and_ai(const int &ai_type) {
    std::unique_ptr<Player> human_player = std::make_unique<Human>();
    human_player->set_board(this->board_num_row, this->board_num_col);
    human_player->set_ships(this->ship_map);
    this->players.push_back(std::move(human_player));

    add_ai(ai_type);
}


void BattleShip::Game::setup_game() {
    for(int i = 0; i < 2; ++i) {
        Player& cur_player = get_current_player();
        cur_player.set_name(playerTurn);
        //cur_player.display_placement_board();
        for (auto ships: ship_container) {
            char ship_name  = ships.get_ship_name();
            int ship_length = ships.get_ship_length();
            std::string orientation_choice;
            int row_choice, col_choice;

            while (true) {
                cur_player.get_ship_direction(ship_name, orientation_choice);
                cur_player.get_ship_placement(ship_name, ship_length, row_choice, col_choice, orientation_choice);
               if(cur_player.valid_placement(row_choice, col_choice, ship_length, orientation_choice)) {
                   break;
               } else {
                   continue;
               }
            }
            cur_player.place_ship(row_choice, col_choice, ship_length, ship_name, orientation_choice);
            cur_player.display_placement_board();
            std::cout << std::endl;
        }
        insert_second_ai();
        change_player_turn();
    }
}

void BattleShip::Game::play_game() {

    int i = 0;
    while(!is_game_over()) {
        int row_choice, col_choice;
        char ship_hit;

        //get_current_player().display_both_game_boards(get_current_player().get_name()); if cur player == human, then we display board
        check_firing_pos(get_current_player().get_name(), row_choice, col_choice, this->board_num_row, this->board_num_col); //needs to change for AI
        check_for_hit(row_choice, col_choice, ship_hit);
        std::cout << std::endl;
        if (is_game_over()) {
            break;
        }
        change_player_turn();
        ++i;
    }

}

bool BattleShip::Game::is_game_over() {
    if (get_opposing_player().check_for_empty_map()) {
        std::cout << get_current_player().get_name() << " won the game!" << std::endl;
        return true;
    } else { return false; }
}

BattleShip::Player& BattleShip::Game::get_current_player() {
    return *this->players.at(playerTurn);
    //Code from Butner Google Drive
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
    //Code from Butner Google Drive
}



void BattleShip::Game::check_for_hit(int row_choice, int col_choice, char& ship_hit) {
    if(get_opposing_player().check_for_hit(row_choice, col_choice, ship_hit)) {
        get_current_player().successful_hit(row_choice, col_choice);
        update_game_for_hit(row_choice, col_choice, ship_hit);
    } else {
        update_game_for_miss(row_choice, col_choice, ship_hit);
    }
}

void BattleShip::Game::update_game_for_hit(int row_choice, int col_choice, char &ship_hit) {
    get_opposing_player().decrement_ship(ship_hit);
    get_opposing_player().ship_was_hit_on_place_board(row_choice, col_choice);
    get_current_player().ship_was_hit_on_firing_board(row_choice, col_choice);

    std::string cur_player = get_current_player().get_name();
    std::string opp_player = get_opposing_player().get_name();
    get_current_player().display_both_game_boards(get_current_player().get_name());
    std::cout << cur_player << " hit " << opp_player << "'s " << ship_hit <<"!" << std::endl;
    check_for_ship_destroyed(ship_hit);
}

void BattleShip::Game::update_game_for_miss(int row_choice, int col_choice, char &ship_hit) {
    get_current_player().ship_was_miss_on_firing_board(row_choice, col_choice);
    get_opposing_player().ship_was_miss_on_place_board(row_choice, col_choice);
    get_current_player().display_both_game_boards(get_current_player().get_name());
    std::cout<< "Missed." << std::endl;

}

void BattleShip::Game::check_for_ship_destroyed(char& ship_name) {
    if (get_opposing_player().check_for_ship_destroyed(ship_name)) {
        get_opposing_player().remove_ship(ship_name);
        std::cout << get_current_player().get_name() << " destroyed " <<
        get_opposing_player().get_name() << "'s " << ship_name << "!" << std::endl;
    }
}


void BattleShip::Game::check_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size) {
    while(true) {
                Board enemy_board = get_opposing_player().get_placement_board();
                get_current_player().get_firing_coords(num1, num2, row_size, col_size, enemy_board);
                if(!is_between(num1, num2, row_size, col_size)) {
                    get_current_player().display_both_game_boards(get_current_player().get_name());
                    continue;
                } else if(!get_current_player().check_for_blank_char(num1, num2)) {
                    get_current_player().display_both_game_boards(get_current_player().get_name()); //something wrong here
                    continue;
                } else {
                    break;
                }
            }

//        Board enemy_board = get_opposing_player().get_placement_board();
//        get_current_player().get_firing_coords(num1, num2, row_size, col_size, enemy_board);

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

void BattleShip::Game::insert_second_ai() {
    if(players.size() ==1) {
        int ai_type;
        get_ai_type(ai_type);
        add_ai(ai_type);
    }

}

void BattleShip::Game::add_ai(const int &ai_type) {
    int cheating_ai = 1, random_ai = 2, hunt_destroy_ai = 3;
    if(ai_type == cheating_ai) {
        std::unique_ptr<Player> ai_player = std::make_unique<CheatingAI>();
        ai_player->set_board(this->board_num_row, this->board_num_col);
        ai_player->set_ships(this->ship_map);
        this->players.push_back(std::move(ai_player));
    }
    else if(ai_type == random_ai) {
        std::unique_ptr<Player> ai_player = std::make_unique<RandomAI>();
        ai_player->set_board(this->board_num_row, this->board_num_col);
        ai_player->set_ships(this->ship_map);
        ai_player->set_coord_vector();
        this->players.push_back(std::move(ai_player));
    }
    else if(ai_type == hunt_destroy_ai) {
        std::unique_ptr<Player> ai_player = std::make_unique<SearchAndDestroyAI>();
        ai_player->set_board(this->board_num_row, this->board_num_col);
        ai_player->set_ships(this->ship_map);
        ai_player->set_coord_vector();
        this->players.push_back(std::move(ai_player));
    }
}




