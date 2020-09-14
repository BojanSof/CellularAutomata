#include <Rule.hpp>
#include <Common.hpp>
#include <exception>

void CA::Rule::addColoringRule(const CA::State &state, const sf::Color &color) {
    coloringRules[state] = color;
}

const sf::Color& CA::Rule::getColor(const CA::State &state) {
    try {
        return coloringRules.at(state);
    } catch(const std::out_of_range &e) {
        return sf::Color::Black;
    }
    return sf::Color::Black;
}