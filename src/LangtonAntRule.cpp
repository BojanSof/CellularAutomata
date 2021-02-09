//ONLY FOR COMPATIBILITY!!!
#include <LangtonAntRule.hpp>
#include <LangtonAnt.hpp>

CA::State CA::LangtonAntRule::getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const {
    return CA::LangtonAnt::STATE_WHITE;
}

CA::State CA::LangtonAntRule::getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const {
    return CA::LangtonAnt::STATE_WHITE;
}