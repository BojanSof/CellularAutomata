#ifndef GRID_HPP
#define GRID_HPP

#include <Cell.hpp>
#include <vector>

namespace CA {

class Grid {    
public:
    Grid();
    Grid(std::size_t r, std::size_t c);
    Grid(std::size_t r, std::size_t c, float cw, float ch);

    std::size_t getRows() const;
    std::size_t getColumns() const;
    const Cell& getCell(std::size_t row, std::size_t column) const;

    void setCellState(std::size_t r, std::size_t c, const CA::State &state, const sf::Color &color);
    void setBorderColor(const sf::Color &color);
    void setBorderThickness(float t);
    void setCellSize(float cw, float ch);

    //test
    void drawRow(sf::RenderWindow *window, std::size_t currentRow) const;

private:
    std::size_t rows, columns;
    std::vector<std::vector<Cell>> cells;
};

}

#endif //GRID_HPP