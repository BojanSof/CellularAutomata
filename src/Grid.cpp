#include <Grid.hpp>

CA::Grid::Grid(int w, int h) {
    width = w;
    height = h;
    
    cells = new Cell*[height];
    for(int i = 0; i < height; i++)
        cells[i] = new Cell[width];
}

CA::Grid::Grid(int w, int h, bool initState) {
    width = w;
    height = h;
    
    cells = new Cell*[height];
    for(int i = 0; i < height; i++) {
        cells[i] = new Cell[width];
        for(int j = 0; j < width; j++)
            cells[i][j] = initState;
    }
}

CA::Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        delete[] cells[i];
        cells[i] = nullptr;
    }
    delete[] cells;
    cells = nullptr;
}

int CA::Grid::getWidth() const {
    return width;
}

int CA::Grid::getHeight() const {
    return height;
}

const CA::Cell& CA::Grid::getCell(int r, int c) const {
    return cells[r][c];
}

void CA::Grid::setCellState(int r, int c, bool s) {
    cells[r][c].setState(s);
}