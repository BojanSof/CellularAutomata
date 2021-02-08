#include <GameOfLife.hpp>
#include <Common.hpp>
#include <iostream>

const CA::State CA::GameOfLife::STATE_ALIVE("ALIVE");
const CA::State CA::GameOfLife::STATE_DEAD("DEAD");

CA::GameOfLife::GameOfLife() : GameOfLife(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::GameOfLife::GameOfLife(std::size_t r, std::size_t c) : GameOfLife(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::GameOfLife::GameOfLife( 
                            std::size_t r, std::size_t c,
                            float cw, float ch
                        ) : GameOfLife(r, c, cw, ch, CA::GameOfLifeRule()) {
}

CA::GameOfLife::GameOfLife( 
                            std::size_t r, std::size_t c,
                            float cw, float ch,
                            const CA::GameOfLifeRule &ru
                        ) : CellularAutomaton(r, c, cw, ch), newStates(r, std::vector<CA::State>(c)) {
    rule = std::make_shared<CA::GameOfLifeRule>(ru);
    //initialize coloring rules
    rule->addColoringRule(STATE_DEAD, sf::Color::White);
    rule->addColoringRule(STATE_ALIVE, sf::Color::Black);
    /*for(std::size_t i = 0; i < r; i++) {
        for(std::size_t j = 0; j < c; j++) {
            newStates[i].push_back(CA::GameOfLife::STATE_DEAD);
        }
    }*/
}

void CA::GameOfLife::initFirstGeneration() {
    for(std::size_t r = 0; r < grid.getRows(); r++) {
        for(std::size_t c = 0; c < grid.getColumns(); c++) {
            const CA::State &state = (rng.randUInt(1,1000) > 500) ? STATE_ALIVE : STATE_DEAD;
            grid.setCellState(r, c, state, rule->getColor(state));
        }
    }
}

void CA::GameOfLife::reset() {
    initFirstGeneration();
}

bool CA::GameOfLife::update() {
    CA::Cell dummy(grid.getCell(0, 0));
    dummy.setStateColor(STATE_DEAD, rule->getColor(STATE_DEAD));
    //determine next states
    for(std::size_t r = 0; r < grid.getRows(); r++) {
        for(std::size_t c = 0; c < grid.getColumns(); c++) {
            const CA::Cell &topLeft = grid.getCell((r + grid.getRows() - 1) % grid.getRows(), (c + grid.getColumns() - 1) % grid.getColumns());
            const CA::Cell &topCenter = grid.getCell((r + grid.getRows() - 1) % grid.getRows(), c);
            const CA::Cell &topRight = grid.getCell((r + grid.getRows() - 1) % grid.getRows(), (c + 1) % grid.getColumns());

            const CA::Cell &midLeft = grid.getCell(r, (c + grid.getColumns() - 1) % grid.getColumns());
            const CA::Cell &midCenter = grid.getCell(r, c);
            const CA::Cell &midRight = grid.getCell(r, (c + 1) % grid.getColumns());

            const CA::Cell &bottomLeft = grid.getCell((r + 1) % grid.getRows(), (c + grid.getColumns() - 1) % grid.getColumns());
            const CA::Cell &bottomCenter = grid.getCell((r + 1) % grid.getRows(), c);
            const CA::Cell &bottomRight = grid.getCell((r + 1) % grid.getRows(), (c + 1) % grid.getColumns());
            /*
            const CA::Cell &topLeft = (r > 0 && c > 0) ? grid.getCell(r - 1, c - 1) : dummy;
            const CA::Cell &topCenter = (r > 0) ? grid.getCell(r - 1, c) : dummy;
            const CA::Cell &topRight = (r > 0 && c < grid.getColumns() - 1) ? grid.getCell(r - 1, c + 1) : dummy;

            const CA::Cell &midLeft = (c > 0) ? grid.getCell(r, c - 1) : dummy;
            const CA::Cell &midCenter = grid.getCell(r, c);
            const CA::Cell &midRight = (c < grid.getColumns() - 1) ? grid.getCell(r, c + 1) : dummy;

            const CA::Cell &bottomLeft = (r < grid.getRows() - 1 && c > 0) ? grid.getCell(r + 1, c - 1) : dummy;
            const CA::Cell &bottomCenter = (r < grid.getRows() - 1) ? grid.getCell(r + 1, c) : dummy;
            const CA::Cell &bottomRight = (r < grid.getRows() - 1 && c < grid.getColumns() - 1) ? grid.getCell(r + 1, c + 1) : dummy;
            */
            CA::State newState = rule->getNewState(
                                                    topLeft, topCenter, topRight,
                                                    midLeft, midCenter, midRight,
                                                    bottomLeft, bottomCenter, bottomRight
                                                );
            newStates[r][c] = newState;
        }
    }
    
    //apply next states
    for(std::size_t r = 0; r < grid.getRows(); r++) {
        for(std::size_t c = 0; c < grid.getColumns(); c++) {
            grid.setCellState(r, c, newStates[r][c], rule->getColor(newStates[r][c]));
        }
    }
    return true;
}