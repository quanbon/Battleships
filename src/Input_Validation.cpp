//
// Created by Quan Nguyen on 4/29/22.
//

#include "Input_Validation.h"
#include "Ships.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>


void BattleShip::lowerInPlace(std::string& string) {
    for (auto& letter: string) {
        letter = tolower(letter);
    }
}

std::string BattleShip::lower(std::string& string) {
    lowerInPlace(string);
    return string;
}


bool BattleShip::is_valid_placement(const std::string& word_to_check) {
    std::string word_check = word_to_check;
    lower(word_check);
    std::vector<std::string> valid_words {"h", "H", "V", "v"};
    for(auto val_words: valid_words) {
        if(val_words == word_check) {
            return true;
        }
    }
    return false;
}

std::string BattleShip::get_player_name(int player_num) {
    std::string line;

    while(true) {
        std::cout << "Player " << player_num + 1 << " please enter your name: ";
        std::getline(std::cin, line);
        std::stringstream line2parse(line);
        std::string word;
        line2parse >> word;
        if (line2parse) {
            std:: string what_is_left;
            line2parse >>what_is_left;
            if (not line2parse) {
                return word;
            }
        }
    }
}

void BattleShip::get_two_ints(std::string player_name, char ship_name, int ship_size, int& num1, int& num2) {
    std::string line;
    while (true) {
        std::cout << player_name << ", enter the row and column you want to place " << ship_name << ", which is " << ship_size;
        std::cout << " long, at with a space in between row and col: ";
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        line2parse >> num1 >> num2;
        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse ) { //if there is nothing left we will fail to read it
                return;
            }
        }
    }
}


bool BattleShip::is_between(int num1, int num2, int row_size, int col_size) {
    return num1 > -1 and num1 < row_size and num2 > -1 and num2 < col_size;
}

void BattleShip::get_ship_direction_choice(std::string player_name, char ship_name, std::string& ship_orientation) {
    std::string line;
    std::string prompt = " horizontally or vertically?\n"
                         "Enter h for horizontal or v for vertical\n"
                         "Your choice: ";

    while(true) {
        std::cout << player_name; //needs player name
        std::cout << ", do you want to place " << ship_name << prompt; //needs ship name
        std::getline(std::cin, line);
        std::stringstream line2parse(line);
        line2parse >> ship_orientation;
        if (line2parse) {
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse and is_valid_placement(ship_orientation)) {
                return;
            }
        }
    }
}

void BattleShip::get_game_type (int& game_type) {
    std::string line;

    while(true) {
        std::cout << "What type of game do you want to play?" << std::endl;
        std::cout << "1. Human vs Human" << std::endl;
        std::cout << "2. Human vs AI" << std::endl;
        std::cout << "3. AI vs AI" << std::endl;
        std::cout << "Your choice: ";
        std::getline(std::cin, line);
        std::stringstream line2parse(line);
        line2parse >> game_type;
        if (line2parse) {
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) {
                return;
            }
        }
    }
}

void BattleShip::get_ai_type (int& player_type) {
    std::string line;

    while(true) {
        std::cout << "What AI do you want?" << std::endl;
        std::cout << "1. Cheating AI" << std::endl;
        std::cout << "2. Random AI" << std::endl;
        std::cout << "3. Hunt Destroy AI" << std::endl;
        std::cout << "Your choice: ";
        std::getline(std::cin, line);
        std::stringstream line2parse(line);
        line2parse >> player_type;
        if (line2parse) {
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) {
                return;
            }
        }
    }
}





