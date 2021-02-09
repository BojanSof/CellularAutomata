#include <LangtonAnt.hpp>
#include <Common.hpp>

const CA::State CA::LangtonAnt::STATE_WHITE("WHITE");
const CA::State CA::LangtonAnt::STATE_BLACK("BLACK");
const CA::State CA::LangtonAnt::STATE_ANT_WHITE("ANT_WHITE");
const CA::State CA::LangtonAnt::STATE_ANT_BLACK("ANT_BLACK");

CA::LangtonAnt::LangtonAnt() : LangtonAnt(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::LangtonAnt::LangtonAnt(std::size_t r, std::size_t c) : LangtonAnt(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::LangtonAnt::LangtonAnt( 
                            std::size_t r, std::size_t c,
                            float cw, float ch
                        ) : CellularAutomaton(r, c, cw, ch) {
    rule = std::make_shared<CA::LangtonAntRule>();
    //initialize coloring rules
    rule->addColoringRule(STATE_WHITE, sf::Color::White);
    rule->addColoringRule(STATE_BLACK, sf::Color::Black);
    rule->addColoringRule(STATE_ANT_WHITE, sf::Color::Red);
    rule->addColoringRule(STATE_ANT_BLACK, sf::Color::Red);
    //initialize grid
    initGrid();
}

void CA::LangtonAnt::initGrid() {
    for(std::size_t r = 0; r < grid.getRows(); r++) {
        for(std::size_t c = 0; c < grid.getColumns(); c++) {
            //const CA::State &state = (rng.randUInt(1,1000) > 500) ? STATE_ALIVE : STATE_DEAD;
            const CA::State &state = STATE_WHITE;
            grid.setCellState(r, c, state, rule->getColor(state));
        }
    }
    //random ant position
    antRow = rng.randUInt(0, grid.getRows() - 1);
    antColumn = rng.randUInt(0, grid.getColumns() - 1);
    antDirection = rng.randUInt(0,3);
    grid.setCellState(antRow, antColumn, STATE_ANT_WHITE, rule->getColor(STATE_ANT_WHITE));
}

void CA::LangtonAnt::reset() {
    initGrid();
}

bool CA::LangtonAnt::update() {
    std::size_t newAntRow, newAntColumn;
    int newAntDirection;
    if(grid.getCell(antRow, antColumn).getState() == CA::LangtonAnt::STATE_ANT_WHITE) {
        grid.setCellState(antRow, antColumn, STATE_BLACK, rule->getColor(STATE_BLACK));
        newAntDirection = (antDirection + 3) % 4;
    } else if(grid.getCell(antRow, antColumn).getState() == CA::LangtonAnt::STATE_ANT_BLACK) {
        grid.setCellState(antRow, antColumn, STATE_WHITE, rule->getColor(STATE_WHITE));
        newAntDirection = (antDirection + 1) % 4;
    }
    antDirection = newAntDirection;
    if(antDirection == 0) { //right
        newAntRow = antRow;
        newAntColumn = (antColumn + 1) % grid.getColumns();
    } else if(antDirection == 1) { // up
        newAntRow = (antRow + grid.getRows() - 1) % grid.getRows();
        newAntColumn = antColumn;
    } else if(antDirection == 2) { //left
        newAntRow = antRow;
        newAntColumn = (antColumn + grid.getColumns() - 1) % grid.getColumns();
    } else if(antDirection == 3) { //down
        newAntRow = (antRow + 1) % grid.getRows();
        newAntColumn = antColumn;
    }
    
    antRow = newAntRow; antColumn = newAntColumn;
    const CA::State &newAntState = (grid.getCell(antRow, antColumn).getState() == STATE_WHITE) ? STATE_ANT_WHITE : STATE_ANT_BLACK;
    grid.setCellState(antRow, antColumn, newAntState, rule->getColor(newAntState));
    return true;
}