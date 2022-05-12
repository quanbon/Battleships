//
// Created by harle on 5/9/2022.
//

#ifndef BATTLESHIP_RANDOM_H
#define BATTLESHIP_RANDOM_H
#include <random>

char rand_orientation (std::mt19937& generator);
int rand_row_or_col (std::mt19937& generator, int max_num);
int get_random_element(std::mt19937& generator, int vector_size);

#endif //BATTLESHIP_RANDOM_H
