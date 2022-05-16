//
// Created by harle on 5/9/2022.
//

#include <random>
#include "Random.h"


char rand_orientation (std::mt19937& generator) {
    std::uniform_int_distribution<int> dist(0, 1);
    int random_num = dist(generator);
    if(random_num == 0) {
        return 'H';
    } else  {
        return 'V';
    }
}

int rand_row_or_col (std::mt19937&  generator, int max_num) {
    std::uniform_int_distribution<int> dist(0, max_num);
    int random_num = dist(generator);
    return random_num;
}

int get_random_element(std::mt19937 &generator, int vector_size) {
    std::uniform_int_distribution<int> dist(0, vector_size); // vector size was getting subtracted by 2
    int random_num = dist(generator);
    return random_num;
}
