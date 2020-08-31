#include <Rule.hpp>
#include <Common.hpp>

CA::Rule::Rule() : number(ELEMENTARY_DEFAULT_RULE) {}

CA::Rule::Rule(unsigned char n) : number(n) {}

CA::State CA::Rule::getNewState(const CA::Cell &left, const CA::Cell &center, const CA::Cell &right) const {
    if(left.getState() == CA::State::OFF && center.getState() == CA::State::OFF && right.getState() == CA::State::OFF) return (number & 1) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::OFF && center.getState() == CA::State::OFF && right.getState() == CA::State::ON) return (number & 2) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::OFF && center.getState() == CA::State::ON && right.getState() == CA::State::OFF) return (number & 4) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::OFF && center.getState() == CA::State::ON && right.getState() == CA::State::ON) return (number & 8) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::ON && center.getState() == CA::State::OFF && right.getState() == CA::State::OFF) return (number & 16) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::ON && center.getState() == CA::State::OFF && right.getState() == CA::State::ON) return (number & 32) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::ON && center.getState() == CA::State::ON && right.getState() == CA::State::OFF) return (number & 64) ? CA::State::ON : CA::State::OFF;
    if(left.getState() == CA::State::ON && center.getState() == CA::State::ON && right.getState() == CA::State::ON) return (number & 128) ? CA::State::ON : CA::State::OFF;
    return CA::State::OFF;
}