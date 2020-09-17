#ifndef ELEMENTARY_HPP
#define ELEMENTARY_HPP

#include <CellularAutomaton.hpp>
#include <ElementaryRule.hpp>
#include <Random.hpp>

namespace CA {

class Elementary : public CA::CellularAutomaton {
public:
    Elementary();
    Elementary(std::size_t rows, std::size_t columns);
    Elementary( std::size_t rows, std::size_t columns,
                float cw, float ch );
    Elementary( std::size_t rows, std::size_t columns,
                float cw, float ch ,
                const CA::ElementaryRule &ru, int frc);
    bool update() override;
    void reset() override;
    std::size_t getNextRow() const;
    void initFirstRow(int c);   //initialize the first row based on flag c
                                //c = -1, cells' state is randomly chosen
                                //c = 0, all cells are OFF
                                //c = 1, all cells are ON
                                //c = 2, only the middle cell is ON


public:
    static const CA::State STATE_BLANK;
    static const CA::State STATE_OFF;
    static const CA::State STATE_ON;
private:
    std::size_t nextRow;
    int firstRowConfig;
    CA::Random rng;
};

}

#endif //ELEMENTARY_HPP