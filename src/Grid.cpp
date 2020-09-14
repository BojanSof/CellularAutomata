#include <Grid.hpp>
#include <Common.hpp>
#include <iostream>

CA::Grid::Grid() : Grid(GRID_ROWS, GRID_COLUMNS, CELL_WIDTH, CELL_HEIGHT) {}

CA::Grid::Grid(std::size_t r, std::size_t c) : Grid(r, c, CELL_WIDTH, CELL_HEIGHT) {}

CA::Grid::Grid(std::size_t r, std::size_t c, float cw, float ch) : 
                rows(r), columns(c),
                cells(std::vector<std::vector<Cell>>(r)) {
    for(std::size_t i = 0; i < rows; i++) {
        for(std::size_t j = 0; j < columns; j++) {
            CA::Cell c(cw, ch);
            c.setPosition(j * cw, i * ch);
            cells[i].push_back(c);
        }
    }
}

std::size_t CA::Grid::getRows() const {
    return rows;
}

std::size_t CA::Grid::getColumns() const {
    return columns;
}

const CA::Cell& CA::Grid::getCell(std::size_t r, std::size_t c) const {
    return cells[r][c];
}

void CA::Grid::setCellState(std::size_t r, std::size_t c, 
                            const CA::State &state, const sf::Color &color) {
    cells[r][c].setStateColor(state, color);
}

void CA::Grid::setBorderColor(const sf::Color &color) {
    for(std::size_t i = 0; i < rows; i++) {
        for(std::size_t j = 0; j < columns; j++) {
            cells[i][j].setOutlineColor(color);
        }
    }
}

void CA::Grid::setBorderThickness(float t) {
    for(std::size_t i = 0; i < rows; i++) {
        for(std::size_t j = 0; j < columns; j++) {
            cells[i][j].setOutlineThickness(t/2);
        }
    }
}

void CA::Grid::setCellSize(float cw, float ch) {
    for(std::size_t i = 0; i < rows; i++) {
        for(std::size_t j = 0; j < columns; j++) {
            cells[i][j].setSize(cw, ch);
        }
    }
}

void CA::Grid::drawRow(sf::RenderWindow *window, std::size_t currentRow) const {
    for(std::size_t c = 0; c < columns; c++)
        window->draw(cells[currentRow][c]);
}