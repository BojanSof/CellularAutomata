#include <State.hpp>

CA::State::State() : value(0) {}
CA::State::State(int v) : value(v) {}

bool CA::State::operator==(const State &s) {
    return (value == s.value);
}

const CA::State CA::State::OFF(0);
const CA::State CA::State::ON(1);