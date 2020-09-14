#ifndef ELEMENTARY_HPP
#define ELEMENTARY_HPP

#include <Grid.hpp>
#include <ElementaryRule.hpp>

namespace CA {

class Elementary {
public:
    Elementary();
    Elementary(std::size_t rows, std::size_t columns);
    Elementary( std::size_t rows, std::size_t columns,
                std::size_t cw, std::size_t ch );
    Elementary( std::size_t rows, std::size_t columns,
                std::size_t cw, std::size_t ch ,
                const CA::ElementaryRule &ru);
    const CA::Grid &getGrid() const;
    std::size_t getNextRow() const;
    bool update(); //returns false if no change is made
public:
    static const CA::State STATE_BLANK;
    static const CA::State STATE_OFF;
    static const CA::State STATE_ON;
private:
    CA::Grid grid;
    std::size_t nextRow;
    CA::ElementaryRule rule;
};

}

#endif //ELEMENTARY_HPP