#include <CellularAutomaton.hpp>
#include <Common.hpp>

CA::CellularAutomaton::CellularAutomaton() : CellularAutomaton(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::CellularAutomaton::CellularAutomaton(std::size_t r, std::size_t c) : CellularAutomaton(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::CellularAutomaton::CellularAutomaton( 
                            std::size_t r, std::size_t c,
                            float cw, float ch
                        ) : grid(r, c, cw, ch) {
}

const CA::Grid& CA::CellularAutomaton::getGrid() const {
    return grid;
}