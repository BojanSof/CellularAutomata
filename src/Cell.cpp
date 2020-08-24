#include <Cell.hpp>

CA::Cell::Cell() {
    state = false;
}

CA::Cell::Cell(bool s) {
    state = s;
}

bool CA::Cell::getState() const {
    return state;
}

void CA::Cell::setState(bool s) {
    state = s;
}