#ifndef COMMON_HPP
#define COMMON_HPP

//default configurations

#include <State.hpp>

namespace CA {
    const float CELL_WIDTH = 100;
    const float CELL_HEIGHT = 100;
    const CA::State DEFAULT_STATE = CA::State("BLANK");
    const unsigned char ELEMENTARY_DEFAULT_RULE = 90;
    const std::size_t GRID_ROWS = 10;
    const std::size_t GRID_COLUMNS = 10;

    const unsigned int APP_WIDTH = 1000;
    const unsigned int APP_HEIGHT = 1024;
    
    const float FPS = 60.0f;
}

#endif //COMMON_HPP