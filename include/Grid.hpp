#ifndef GRID_HPP
#define GRID_HPP

#include <Cell.hpp>
#include <vector>

namespace CA {

class Grid {
public:
    Grid();
    Grid(unsigned int r, unsigned int c);
    Grid(unsigned int r, unsigned int c, unsigned int cw, unsigned int ch);

    unsigned int getRows() const;
    unsigned int getColumns() const;
    const Cell& getCell(int row, int column) const;

    void setCellState(int r, int c, State s);

private:
    unsigned int rows, columns;
    std::vector<std::vector<Cell>> cells;
};

}

#endif //GRID_HPP