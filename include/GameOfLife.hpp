#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include <CellularAutomaton.hpp>
#include <Random.hpp>
#include <GameOfLifeRule.hpp>

namespace CA {

class GameOfLife : public CA::CellularAutomaton {
public:
    GameOfLife();
    GameOfLife(std::size_t rows, std::size_t columns);
    GameOfLife( std::size_t rows, std::size_t columns,
                float cw, float ch );
    GameOfLife( std::size_t rows, std::size_t columns,
                float cw, float ch ,
                const CA::GameOfLifeRule &ru);
    bool update() override;
    void reset() override;
    void initFirstGeneration(); //randomly initialize first generation cell states

public:
    static const CA::State STATE_ALIVE;
    static const CA::State STATE_DEAD;
private:
    CA::Random rng;
    std::vector<std::vector<CA::State>> newStates;
};

}

#endif //GAME_OF_LIFE_HPP