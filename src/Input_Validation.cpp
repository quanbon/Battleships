//
// Created by Quan Nguyen on 4/29/22.
//

#include "Input_Validation.h"
#include "Ships.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>



void lowerInPlace(std::string& string) {
    for (auto& letter: string) {
        letter = tolower(letter);
    }
}

void lower(std::string& string) {
    lowerInPlace(string);
}

bool is_valid_placement(const std::string& word_to_check) {
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

std::string get_ship_direction_choice(std::string player_name, char ship_name) {
    std::string line;
    std::string prompt = " horizontally or vertically?\n "
                         "Enter h for horizontal or v for vertical\n"
                         "Your choice: ";

    while(true) {
        std::cout << player_name; //needs player name
        std::cout << ", do you want to place " << ship_name << prompt; //needs ship name
        std::getline(std::cin, line);
        std::stringstream line2parse(line);
        std::string word;
        line2parse >> word;
        if (line2parse) {
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse and is_valid_placement(word)) {
                return word;
            }
        }
    }
}

// cin >> num_rows >> num_cols for the input

bool is_row_inbound (const int& user_row_choice, const int& num_rows, int ship_length) {
    if (user_row_choice < 0 or user_row_choice > num_rows - 1) {
        return false;
    } else if (user_row_choice + ship_length > num_rows) { // checks if the row that its at plus the ship size is good
        return false;                                      // so if num colws
    } else { return true; }
}

bool is_col_inbound (const int& user_col_choice, const int& num_cols, int ship_length) {
    if (user_col_choice < 0 or user_col_choice > num_cols - 1) {
        return false;
    } else if (user_col_choice + ship_length > num_cols) {
        return false;
    } else { return true;}
}


void get_coords_for_ship_placement(int& num_rows, int& num_cols, std::string player_name, char ship_name,
                                   int ship_length, std::string choice_of_orientation) { //added choice of orientation to see if I could make an if else with
                                                                                         //the option they choose so if they choose vertical or horizontal
                                                                                         // I check either row or col accordingly :)))
    std::string line;
    std::string prompt = " long, at with a space in between row and col: ";

    while (true) {
        std::cout << player_name;
        std::cout << ", enter the row and column you want to place "
                  << ship_name << ", which is " << ship_length << prompt;
        std::getline(std::cin, line); //grabs the entire line
        std::stringstream line2parse(line);
        line2parse >> num_rows >> num_cols;

        if (line2parse) { //if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { //if there is nothing left we will fail to read it
                return;
            }
        }
    }
}
