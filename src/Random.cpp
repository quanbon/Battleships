//
// Created by harle on 5/9/2022.
//

#include <random>

char rand_orientation (std::minstd_rand& generator) {
    std::uniform_int_distribution<int> dist(0, 1);
    int random_num = dist(generator);
    if(random_num == 0) {
        return 'H';
    } else if (random_num == 1) {
        return 'V';
    }
    return 'X';
}

int rand_row_or_col (std::minstd_rand& generator, int max_num) {
    std::uniform_int_distribution<int> dist(0, max_num);
    int random_num = dist(generator);
    return random_num;
}
