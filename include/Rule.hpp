#ifndef RULE_HPP
#define RULE_HPP

#include <State.hpp>
#include <Cell.hpp>
#include <map>

namespace CA {

class Rule {
public:
    //void addTransitionRule(const CA::State &oldState, const CA::State &newState);
    void addColoringRule(const CA::State &state, const sf::Color &color);

    const sf::Color &getColor(const CA::State &state);

    virtual CA::State getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const = 0;
    virtual CA::State getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const = 0;
private:
    //std::unordered_map<CA::State, CA::State> transitionRules;
    std::map<CA::State, sf::Color, CA::StateCompare> coloringRules;
};

}

#endif //RULE_HPP