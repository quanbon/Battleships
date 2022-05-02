//
// Created by harle on 5/2/2022.
//

#include <fstream>
#include "Ships.h"
#include "file_reader.h"

void read_file (std::ifstream& src, int& num_rows, int& num_cols) {
    num_rows = src.get(); // If the file is always valid, the first
    num_cols = src.get(); // 3 integers we get will be the rows, cols
    const int num_ships = src.get(); // and the amount of ships that we need.

    for (int i = 0; i < num_ships; i++) {
        src >> ship_name;
        src >> ship_length;

        // put into an unordered map or vector to store the name
    }
}