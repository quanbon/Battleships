//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_INPUT_VALIDATION_H
#define BATTLESHIPS_INPUT_VALIDATION_H

#include <string>

namespace BattleShip {
    std::string get_player_name(int player_num);
    void get_ship_direction_choice(std::string player_name, char ship_name, std::string& ship_orientation);
    void get_two_ints(std::string player_name, char ship_name, int ship_size, int& num1, int& num2);
    bool is_between(int num1, int num2, int row_size, int col_size);
    bool is_valid_placement(const std::string& word_to_check);
    std::string lower(std::string& string);
    void lowerInPlace(std::string& string);
    void get_firing_pos(std::string player_name, int& num1, int& num2, int row_size, int col_size);
    void get_type_game (int& game_type);
    void get_player_type (int& player_type);


}



#endif //BATTLESHIPS_INPUT_VALIDATION_H
