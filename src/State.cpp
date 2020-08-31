#include <State.hpp>

CA::State::State() : value() {}
CA::State::State(std::string v) : value(v) {}
CA::State::State(const char *v) : value(v) {}

bool CA::State::operator==(const State &s) {
    return (value == s.value);
}

const CA::State CA::State::OFF = CA::State("OFF");
const CA::State CA::State::ON = CA::State("ON");