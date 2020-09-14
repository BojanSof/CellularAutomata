#include <Elementary.hpp>
#include <Common.hpp>
#include <ctime>
#include <cstdlib>

const CA::State CA::Elementary::STATE_BLANK("BLANK");
const CA::State CA::Elementary::STATE_OFF("OFF");
const CA::State CA::Elementary::STATE_ON("ON");

CA::Elementary::Elementary() : Elementary(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::Elementary::Elementary(std::size_t r, std::size_t c) : Elementary(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::Elementary::Elementary( 
                            std::size_t r, std::size_t c,
                            std::size_t cw, std::size_t ch
                        ) : Elementary(r, c, cw, ch, CA::ElementaryRule()) {
}

CA::Elementary::Elementary( 
                            std::size_t r, std::size_t c,
                            std::size_t cw, std::size_t ch,
                            const CA::ElementaryRule &ru
                        ) : grid(r, c, cw, ch), nextRow(1), rule(ru) {
    //initialize coloring rules
    rule.addColoringRule(STATE_BLANK, sf::Color::Black);
    rule.addColoringRule(STATE_OFF, sf::Color(0, 71, 133));
    rule.addColoringRule(STATE_ON, sf::Color(255, 210, 0));

    for(std::size_t c = 0; c < grid.getColumns(); c++)
        grid.setCellState(0, c, STATE_OFF, rule.getColor(STATE_OFF));
    grid.setCellState(0, grid.getColumns() / 2, STATE_ON, rule.getColor(STATE_ON));
}

const CA::Grid& CA::Elementary::getGrid() const {
    return grid;
}

std::size_t CA::Elementary::getNextRow() const {
    return nextRow;
}

bool CA::Elementary::update() {
    if(nextRow >= grid.getRows()) return false;

    for(std::size_t column = 1; column < grid.getColumns() - 1; column++) {
        const CA::Cell &left = grid.getCell(nextRow - 1, column - 1);
        const CA::Cell &center = grid.getCell(nextRow - 1, column);
        const CA::Cell &right = grid.getCell(nextRow - 1, column + 1);
        CA::State newState = rule.getNewState(left, center, right);
        grid.setCellState(  nextRow, column, 
                            newState,
                            rule.getColor(newState));
    }
    grid.setCellState(nextRow, 0, STATE_OFF, rule.getColor(STATE_OFF));
    grid.setCellState(nextRow, grid.getColumns() - 1, STATE_ON, rule.getColor(STATE_ON));
    nextRow += 1;
    return true;
}