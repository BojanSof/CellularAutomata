#include <BriansBrainRule.hpp>
#include <BriansBrain.hpp>

CA::State CA::BriansBrainRule::getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const {
    return CA::BriansBrain::STATE_OFF;
}

CA::State CA::BriansBrainRule::getNewState(  
                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                        ) const {
    if(midCenter.getState() == CA::BriansBrain::STATE_ON) return CA::BriansBrain::STATE_DYING;
    if(midCenter.getState() == CA::BriansBrain::STATE_DYING) return CA::BriansBrain::STATE_OFF;
    int on = 0;
    if(topLeft.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(topCenter.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(topRight.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(midLeft.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(midRight.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(bottomLeft.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(bottomCenter.getState() == CA::BriansBrain::STATE_ON) on +=1;
    if(bottomRight.getState() == CA::BriansBrain::STATE_ON) on +=1;

    if(on == 2) return CA::BriansBrain::STATE_ON; // the current cell was OFF and has exactly two ON neighbors

    return CA::BriansBrain::STATE_OFF;
}