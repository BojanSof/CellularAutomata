#ifndef ELEMENTARYRULE_HPP
#define ELEMENTARYRULE_HPP

#include <Rule.hpp>

namespace CA {

class ElementaryRule : public CA::Rule {
public:
    ElementaryRule();
    ElementaryRule(unsigned char n);
    CA::State getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const;
    CA::State getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const;
private:
    unsigned char number;   //8 bit number, where each bit represents how to set the state of the cell, 
                            //based on the cell's state and its neighbours
                            //ex. if current state of the cell is ON, and the left neighbours' state is ON and the other is OFF,
                            //the next state of the cell will be determined by the bit value on position 0b110 = 6
};

}
#endif //ELEMENTARYRULE_HPP