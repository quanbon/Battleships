//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_INPUT_VALIDATION_H
#define BATTLESHIPS_INPUT_VALIDATION_H

#include <string>


void get_coords_for_ship_placement(int& num_rows, int& num_cols, std::string player_name, char ship_name,
                                       int ship_length);

std::string get_player_name(int player_num);

std::string get_ship_direction_choice(std::string player_name, char ship_name);


#endif //BATTLESHIPS_INPUT_VALIDATION_H
