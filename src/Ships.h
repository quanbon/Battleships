//
// Created by Quan Nguyen on 4/29/22.
//

#ifndef BATTLESHIPS_SHIPS_H
#define BATTLESHIPS_SHIPS_H

namespace BattleShip {
    class Ships {
    public:
        Ships();

        Ships(char name, int length);

        char get_ship_name();
        int get_ship_length();
        char get_ship_orientation();


    private:
        char ship_orientation;
        char ship_name;
        int ship_length;


    };
}




#endif //BATTLESHIPS_SHIPS_H
