//
// Created by Quan Nguyen on 4/29/22.
//

#include "Input_Validation.h"
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

std::string clean_string(std::string string) {
    auto user_choice = string;
    lower(user_choice);
    user_choice.erase(remove(user_choice.begin(), user_choice.end(), '('), user_choice.end());
    user_choice.erase(remove(user_choice.begin(), user_choice.end(), ')'), user_choice.end());
    user_choice.erase(user_choice.begin() + 1, user_choice.end());

    return user_choice;
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

std::string get_ship_direction_choice() {
    std::string line;
    std::string prompt = " horizontally or vertically?\n "
                         "Enter h for horizontal or v for vertical\n"
                         "Your choice: ";

    while(true) {
        //std::cout << name; //needs player name
        //std::cout << ", do you want to place " << ship_name << prompt; //needs ship name
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

bool is_row_inbound (const int& user_row_choice, const int& num_rows) {
    if (user_row_choice < 0 or user_row_choice > num_rows - 1) {
        return false;
    } else { return true; }
}

bool is_col_inbound (const int& user_col_choice, const int& num_cols) {
    if (user_col_choice < 0 or user_col_choice > num_cols - 1) {
        return false;
    } else { return true; }
}



