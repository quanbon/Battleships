//
// Created by harle on 5/9/2022.
//

#include <random>

int rand_orientation (std::mt19937& rand_gen) {
    std::uniform_int_distribution<int> dist(0, 1);
    int random_num = dist(rand_gen);
    return random_num;
}

int rand_row_or_col (std::mt19937& rand_gen, int max_num) {
    std::uniform_int_distribution<int> dist(0, max_num);
    int random_num = dist(rand_gen);
    return random_num;
}
