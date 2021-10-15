#include <BriansBrain.hpp>
#include <Common.hpp>
#include <iostream>

const CA::State CA::BriansBrain::STATE_ON("ON");
const CA::State CA::BriansBrain::STATE_OFF("OFF");
const CA::State CA::BriansBrain::STATE_DYING("DYING");

CA::BriansBrain::BriansBrain() : BriansBrain(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::BriansBrain::BriansBrain(std::size_t r, std::size_t c) : BriansBrain(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::BriansBrain::BriansBrain( 
                            std::size_t r, std::size_t c,
                            float cw, float ch
                        ) : BriansBrain(r, c, cw, ch, CA::BriansBrainRule()) {
}

CA::BriansBrain::BriansBrain( 
                            std::size_t r, std::size_t c,
                            float cw, float ch,
                            const CA::BriansBrainRule &ru
                        ) : CellularAutomaton(r, c, cw, ch), newStates(r, std::vector<CA::State>(c)) {
    rule = std::make_shared<CA::BriansBrainRule>(ru);
    //initialize coloring rules
    rule->addColoringRule(STATE_OFF, sf::Color::Black);
    rule->addColoringRule(STATE_ON, sf::Color::White);
    rule->addColoringRule(STATE_DYING, sf::Color::Blue);
}

void CA::BriansBrain::initFirstGeneration() {
    for(std::size_t r = 0; r < grid.getRows(); r++) {
        for(std::size_t c = 0; c < grid.getColumns(); c++) {
            const CA::State &state = (rng.randUInt(1,1000) > 500) ? STATE_ON : STATE_OFF;
            grid.setCellState(r, c, state, rule->getColor(state));
        }
    }
}

void CA::BriansBrain::reset() {
    initFirstGeneration();
}

bool CA::BriansBrain::update() {
    CA::Cell dummy(grid.getCell(0, 0));
    dummy.setStateColor(STATE_OFF, rule->getColor(STATE_OFF));
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