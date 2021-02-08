#include <GameOfLifeRule.hpp>
#include <GameOfLife.hpp>

CA::State CA::GameOfLifeRule::getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const {
    return CA::GameOfLife::STATE_DEAD;
}

CA::State CA::GameOfLifeRule::getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const {
    int alive = 0, dead = 0;
    if(topLeft.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(topLeft.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(topCenter.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(topCenter.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(topRight.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(topRight.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(midLeft.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(midLeft.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(midRight.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(midRight.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(bottomLeft.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(bottomLeft.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(bottomCenter.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(bottomCenter.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;
    if(bottomRight.getState() == CA::GameOfLife::STATE_ALIVE) alive +=1;
    else if(bottomRight.getState() == CA::GameOfLife::STATE_DEAD) dead +=1;

    if(midCenter.getState() == CA::GameOfLife::STATE_ALIVE) {
        if(alive == 2 || alive == 3) return CA::GameOfLife::STATE_ALIVE;
    } else if(midCenter.getState() == CA::GameOfLife::STATE_DEAD) {
        if(alive == 3) return CA::GameOfLife::STATE_ALIVE;
    }

    return CA::GameOfLife::STATE_DEAD;
}