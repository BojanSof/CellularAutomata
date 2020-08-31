#include <Grid.hpp>
#include <Common.hpp>
#include <iostream>

CA::Grid::Grid() : Grid(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::Grid::Grid(unsigned int r, unsigned int c) : Grid(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::Grid::Grid(unsigned int r, unsigned int c, unsigned int cw, unsigned int ch) : 
                rows(r), columns(c),
                cells(std::vector<std::vector<Cell>>(r)) {
    for(unsigned int i = 0; i < rows; i++) {
        for(unsigned int j = 0; j < columns; j++) {
            CA::Cell c(cw, ch);
            c.setPosition(j * cw, i * ch);
            cells[i].push_back(c);
        }
    }
}

unsigned int CA::Grid::getRows() const {
    return rows;
}

unsigned int CA::Grid::getColumns() const {
    return columns;
}

const CA::Cell& CA::Grid::getCell(int r, int c) const {
    return cells[r][c];
}

void CA::Grid::setCellState(int r, int c, CA::State s) {
    cells[r][c].setState(s);
}