#ifndef RULE_HPP
#define RULE_HPP

#include <State.hpp>
#include <Cell.hpp>

namespace CA {

class Rule {
public:
    Rule();
    Rule(unsigned char n);
    CA::State getNewState(const CA::Cell &left, const CA::Cell &center, const CA::Cell &right) const;
private:
    unsigned char number;   //8 bit number, where each bit represents how to set the state of the cell, 
                            //based on the cell's state and its neighbours
                            //ex. if current state of the cell is ON, and the left neighbours' state is ON and the other is OFF,
                            //the next state of the cell will be determined by the bit value on position 0b110 = 6

};

}

#endif //RULE_HPP