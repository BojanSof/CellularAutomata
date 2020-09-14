#include <State.hpp>

CA::State::State() : value() {}
CA::State::State(std::string v) : value(v) {}
CA::State::State(const char *v) : value(v) {}

bool CA::State::operator==(const CA::State &s) const{
    return (value == s.value);
}

bool CA::StateCompare::operator() (const State &s1, const State &s2) const {
       return s1.getValue() < s2.getValue();
}