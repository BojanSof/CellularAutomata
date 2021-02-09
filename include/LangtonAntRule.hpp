//ONLY FOR COMPATIBILITY!!!
#ifndef LANGTON_ANT_RULE_HPP
#define LANGTON_ANT_RULE_HPP

#include <Rule.hpp>

namespace CA {

class LangtonAntRule : public CA::Rule {
public:
    LangtonAntRule() = default;
    CA::State getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const override;
    CA::State getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const override;
private:
};

}

#endif //LANGTON_ANT_RULE_HPP