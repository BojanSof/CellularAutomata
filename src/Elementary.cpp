#include <Elementary.hpp>
#include <Common.hpp>
#include <ctime>
#include <cstdlib>

CA::Elementary::Elementary() : Elementary(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::Elementary::Elementary(unsigned int r, unsigned int c) : Elementary(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::Elementary::Elementary( 
                            unsigned int r, unsigned int c,
                            unsigned int cw, unsigned int ch
                        ) : Elementary(r, c, cw, ch, CA::Rule()) {
}

CA::Elementary::Elementary( 
                            unsigned int r, unsigned int c,
                            unsigned int cw, unsigned int ch,
                            const CA::Rule &ru
                        ) : grid(r, c, cw, ch), nextRow(1), rule(ru) {
    for(unsigned int c = 0; c < grid.getColumns(); c++)
        grid.setCellState(0, c, CA::State::OFF);
    grid.setCellState(0, grid.getColumns() / 2, CA::State::ON);
}

const CA::Grid& CA::Elementary::getGrid() const {
    return grid;
}

unsigned int CA::Elementary::getNextRow() const {
    return nextRow;
}

bool CA::Elementary::update() {
    if(nextRow >= grid.getRows()) return false;

    for(unsigned int column = 1; column < grid.getColumns() - 1; column++) {
        const CA::Cell &left = grid.getCell(nextRow - 1, column - 1);
        const CA::Cell &center = grid.getCell(nextRow - 1, column);
        const CA::Cell &right = grid.getCell(nextRow - 1, column + 1);
        grid.setCellState(nextRow, column, rule.getNewState(left, center, right));
    }
    grid.setCellState(nextRow, 0, CA::State::OFF);
    grid.setCellState(nextRow, grid.getColumns() - 1, CA::State::ON);
    nextRow += 1;
    return true;
}