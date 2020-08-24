#ifndef GRID_HPP
#define GRID_HPP

#include <Cell.hpp>

namespace CA {

class Grid {
public:
    Grid(int w, int h);
    Grid(int w, int h, bool initState);
    ~Grid();

    int getWidth() const;
    int getHeight() const;
    const Cell& getCell(int r, int c) const;

    void setCellState(int r, int c, bool s);

private:
    int width, height;
    Cell **cells;
};

}

#endif //GRID_HPP