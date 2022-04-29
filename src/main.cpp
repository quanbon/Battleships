#include <iostream>
#include "board.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Battleships::Board a(10, 10);
    a.display_board();

    return 0;
}
