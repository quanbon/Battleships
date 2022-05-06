//
// Created by harle on 5/2/2022.
//

#ifndef BATTLESHIPS_FILE_READER_H
#define BATTLESHIPS_FILE_READER_H

namespace BattleShip {
    void read_config_file (std::ifstream& src, int& num_rows, int& num_cols, std::vector<BattleShip::Ships>& ship_container);

}






#endif //BATTLESHIPS_FILE_READER_H
