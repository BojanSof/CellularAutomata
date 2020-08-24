#include <Cell.hpp>
#include <Common.hpp>

CA::Cell::Cell() : Cell(DEFAULT_STATE, CELL_WIDTH, CELL_HEIGHT) {}

CA::Cell::Cell(State s) : Cell(s, CELL_WIDTH, CELL_HEIGHT) {}

CA::Cell::Cell(unsigned int w, unsigned int h) : Cell(DEFAULT_STATE, w, h) {}

CA::Cell::Cell(State s, unsigned int w, unsigned int h) :
                            width(w), height(h),
                            rect(sf::Vector2f(w, h)) {
    setState(s);
}

CA::State CA::Cell::getState() const {
    return state;
}

unsigned int CA::Cell::getWidth() const {
    return width;
}

unsigned int CA::Cell::getHeight() const {
    return height;
}

void CA::Cell::setState(CA::State s) {
    state = s;
    if(state == CA::State::ON) setColor(sf::Color::White);
    else if(state == CA::State::OFF) setColor(sf::Color::Black);
    else setColor(sf::Color::Green);
}

void CA::Cell::setWidth(unsigned int w) {
    width = w;
}

void CA::Cell::setHeight(unsigned int h) {
    height = h;
}

void CA::Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void CA::Cell::setPosition(float x, float y) {
    rect.setPosition(x,y);
}

sf::Vector2f CA::Cell::getPosition() const {
    return rect.getPosition();
}

void CA::Cell::setColor(sf::Color color) {
    rect.setFillColor(color);
}