#ifndef ELEMENTARY_HPP
#define ELEMENTARY_HPP

#include <Grid.hpp>
#include <Rule.hpp>

namespace CA {

class Elementary {
public:
    Elementary();
    Elementary(unsigned int r, unsigned int c);
    Elementary( unsigned int r, unsigned int c,
                unsigned int cw, unsigned int ch );
    Elementary( unsigned int r, unsigned int c,
                unsigned int cw, unsigned int ch ,
                const CA::Rule &ru);
    const CA::Grid &getGrid() const;
    unsigned int getNextRow() const;
    bool update(); //returns false if no change is made
private:
    CA::Grid grid;
    unsigned int nextRow;
    CA::Rule rule;
};

}

#endif //ELEMENTARY_HPP