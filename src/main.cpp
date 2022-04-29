#include <iostream>
#include "board.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Battleships::Board a(10, 10);
    a.display_board();

    //Just Testing if git works here
    Battleships::Board b(7, 7);

    std::cout << std::endl;

    b.display_board();


    return 0;
}
