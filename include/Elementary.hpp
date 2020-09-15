#ifndef ELEMENTARY_HPP
#define ELEMENTARY_HPP

#include <CellularAutomaton.hpp>
#include <ElementaryRule.hpp>

namespace CA {

class Elementary : public CA::CellularAutomaton {
public:
    Elementary();
    Elementary(std::size_t rows, std::size_t columns);
    Elementary( std::size_t rows, std::size_t columns,
                float cw, float ch );
    Elementary( std::size_t rows, std::size_t columns,
                float cw, float ch ,
                const CA::ElementaryRule &ru);
    bool update() override;
    void reset() override;
    std::size_t getNextRow() const;
public:
    static const CA::State STATE_BLANK;
    static const CA::State STATE_OFF;
    static const CA::State STATE_ON;
private:
    std::size_t nextRow;
};

}

#endif //ELEMENTARY_HPP