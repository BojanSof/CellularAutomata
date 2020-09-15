#ifndef CELLULARAUTOMATON_HPP
#define CELLULARAUTOMATON_HPP

#include <Grid.hpp>
#include <Rule.hpp>
#include <memory>

namespace CA {

class CellularAutomaton {
public:
    CellularAutomaton();
    CellularAutomaton(std::size_t rows, std::size_t columns);
    CellularAutomaton(  std::size_t rows, std::size_t columns,
                        float cw, float ch );
    const CA::Grid &getGrid() const;
    virtual void reset() = 0;
    virtual bool update() = 0; //returns false if no change is made
protected:
    CA::Grid grid;
    std::shared_ptr<CA::Rule> rule;
};

}

#endif //CELLULARAUTOMAION_HPP