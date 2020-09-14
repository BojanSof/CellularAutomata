#include <Cell.hpp>
#include <Common.hpp>

CA::Cell::Cell() : Cell(DEFAULT_STATE, CELL_WIDTH, CELL_HEIGHT) {}

CA::Cell::Cell(const CA::State &s) : Cell(s, CELL_WIDTH, CELL_HEIGHT) {}

CA::Cell::Cell(float w, float h) : Cell(DEFAULT_STATE, w, h) {}

CA::Cell::Cell(const CA::State &s, float w, float h) :
                            rect(sf::Vector2f(w, h)) {
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(0);
    setState(s);
}

void CA::Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}

const CA::State& CA::Cell::getState() const {
    return state;
}

float CA::Cell::getWidth() const {
    return rect.getSize().x;
}

float CA::Cell::getHeight() const {
    return rect.getSize().y;
}

const sf::Vector2f& CA::Cell::getPosition() const {
    return rect.getPosition();
}

const sf::Vector2f& CA::Cell::getSize() const {
    return rect.getSize();
}

void CA::Cell::setState(const CA::State &s) {
    state = s;
    //if(state == CA::State::ON) setColor(sf::Color(255, 210, 0));
    //else if(state == CA::State::OFF) setColor(sf::Color(0, 71, 133));
    //else setColor(sf::Color::Black);
}

void CA::Cell::setWidth(float w) {
    rect.setSize(sf::Vector2f(w, rect.getSize().y));
}

void CA::Cell::setHeight(float h) {
    rect.setSize(sf::Vector2f(rect.getSize().x, h));
}

void CA::Cell::setPosition(float x, float y) {
    rect.setPosition(x,y);
}

void CA::Cell::setSize(float w, float h) {
    rect.setSize(sf::Vector2f(w, h));
}

void CA::Cell::setColor(const sf::Color &color) {
    rect.setFillColor(color);
}

void CA::Cell::setOutlineColor(const sf::Color &color) {
    rect.setOutlineColor(color);
}

void CA::Cell::setOutlineThickness(float t) {
    rect.setOutlineThickness(t);
}

void CA::Cell::setStateColor(const CA::State &s, const sf::Color &c) {
    setState(s);
    setColor(c);
}