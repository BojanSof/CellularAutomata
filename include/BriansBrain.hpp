#ifndef BRIANS_BRAIN_HPP
#define BRIANS_BRAIN_HPP

#include <CellularAutomaton.hpp>
#include <Random.hpp>
#include <BriansBrainRule.hpp>

namespace CA {

class BriansBrain : public CA::CellularAutomaton {
public:
    BriansBrain();
    BriansBrain(std::size_t rows, std::size_t columns);
    BriansBrain( std::size_t rows, std::size_t columns,
                float cw, float ch );
    BriansBrain( std::size_t rows, std::size_t columns,
                float cw, float ch ,
                const CA::BriansBrainRule &ru);
    bool update() override;
    void reset() override;
    void initFirstGeneration(); //randomly initialize first generation cell states

public:
    static const CA::State STATE_OFF;
    static const CA::State STATE_ON;
    static const CA::State STATE_DYING;
private:
    CA::Random rng;
    std::vector<std::vector<CA::State>> newStates;
};

}

#endif //BRIANS_BRAIN_HPP