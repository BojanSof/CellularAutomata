#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <Common.hpp>
#include <string>

namespace CA {

class Configuration {
public:
    Configuration(  
                    unsigned int w = CA::APP_WIDTH, unsigned int h = CA::APP_HEIGHT,
                    std::size_t r = CA::GRID_ROWS, std::size_t c = GRID_COLUMNS,
                    float cw = CA::CELL_WIDTH, float ch = CA::CELL_HEIGHT
                );

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    std::size_t getRows() const;
    std::size_t getColumns() const;
    float getCellWidth() const;
    float getCellHeight() const;

    void setWidth(unsigned int w);
    void setHeight(unsigned int h);
    void setRows(std::size_t r);
    void setColumns(std::size_t c);
    void setCellWidth(float cw);
    void setCellHeight(float ch);
private:
    unsigned int width, height;
    std::size_t rows, columns;
    float cellWidth, cellHeight;
};

}

#endif //CONFIGURATION_HPP