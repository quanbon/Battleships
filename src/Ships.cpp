//
// Created by Quan Nguyen on 4/29/22.
//

#include "Ships.h"
#include <iostream>

BattleShip::Ships::Ships() {

}

BattleShip::Ships::Ships(char name, int length) : ship_name(name), ship_length(length) {

}

char BattleShip::Ships::get_ship_name() {
    return this->ship_name;

}

int BattleShip::Ships::get_ship_length() {
    return this->ship_length;
}

char BattleShip::Ships::get_ship_orientation() {
    return this->ship_orientation;
}