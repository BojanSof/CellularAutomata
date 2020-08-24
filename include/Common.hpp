#ifndef COMMON_HPP
#define COMMON_HPP

//default configurations

#include <State.hpp>

namespace CA {
    const unsigned int CELL_WIDTH = 100;
    const unsigned int CELL_HEIGHT = 100;
    const State DEFAULT_STATE = State::OFF;
    const unsigned int GRID_ROWS = 10;
    const unsigned int GRID_COLUMNS = 10;

    const unsigned int APP_WIDTH = 1000;
    const unsigned int APP_HEIGHT = 1024;
}

#endif //COMMON_HPP