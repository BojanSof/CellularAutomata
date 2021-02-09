#ifndef LANGTON_ANT_HPP
#define LANGTON_ANT_HPP

#include <CellularAutomaton.hpp>
#include <Random.hpp>
#include <LangtonAntRule.hpp>

namespace CA {

class LangtonAnt : public CA::CellularAutomaton {
public:
    LangtonAnt();
    LangtonAnt(std::size_t rows, std::size_t columns);
    LangtonAnt( std::size_t rows, std::size_t columns,
                float cw, float ch );
    bool update() override;
    void reset() override;
    void initGrid();
public:
    static const CA::State STATE_WHITE;
    static const CA::State STATE_BLACK;
    static const CA::State STATE_ANT_WHITE;
    static const CA::State STATE_ANT_BLACK;
private:
    CA::Random rng;
    std::size_t antRow, antColumn;
    int antDirection;   //0 - right, 1 - up, 2 - left, 3 - down
};

}

#endif //LANGTON_ANT_HPP