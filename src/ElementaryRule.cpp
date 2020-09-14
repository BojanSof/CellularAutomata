#include <ElementaryRule.hpp>
#include <Common.hpp>
#include <Elementary.hpp>

CA::ElementaryRule::ElementaryRule() : number(ELEMENTARY_DEFAULT_RULE) {}

CA::ElementaryRule::ElementaryRule(unsigned char n) : number(n) {}

CA::State CA::ElementaryRule::getNewState( const CA::Cell &left, const CA::Cell &center, const CA::Cell &right ) const {
    if(left.getState() == CA::Elementary::STATE_OFF && center.getState() == CA::Elementary::STATE_OFF && right.getState() == CA::Elementary::STATE_OFF) return (number & 1) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_OFF && center.getState() == CA::Elementary::STATE_OFF && right.getState() == CA::Elementary::STATE_ON) return (number & 2) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_OFF && center.getState() == CA::Elementary::STATE_ON && right.getState() == CA::Elementary::STATE_OFF) return (number & 4) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_OFF && center.getState() == CA::Elementary::STATE_ON && right.getState() == CA::Elementary::STATE_ON) return (number & 8) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_ON && center.getState() == CA::Elementary::STATE_OFF && right.getState() == CA::Elementary::STATE_OFF) return (number & 16) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_ON && center.getState() == CA::Elementary::STATE_OFF && right.getState() == CA::Elementary::STATE_ON) return (number & 32) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_ON && center.getState() == CA::Elementary::STATE_ON && right.getState() == CA::Elementary::STATE_OFF) return (number & 64) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(left.getState() == CA::Elementary::STATE_ON && center.getState() == CA::Elementary::STATE_ON && right.getState() == CA::Elementary::STATE_ON) return (number & 128) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    return CA::Elementary::STATE_OFF;
}

CA::State CA::ElementaryRule::getNewState(  
                                            const CA::Cell &topLeft, const CA::Cell &topCenter, const CA::Cell &topRight,
                                            const CA::Cell &midLeft, const CA::Cell &midCenter, const CA::Cell &midRight,
                                            const CA::Cell &bottomLeft, const CA::Cell &bottomCenter, const CA::Cell &bottomRight
                                        ) const {
    if(midLeft.getState() == CA::Elementary::STATE_OFF && midCenter.getState() == CA::Elementary::STATE_OFF && midRight.getState() == CA::Elementary::STATE_OFF) return (number & 1) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_OFF && midCenter.getState() == CA::Elementary::STATE_OFF && midRight.getState() == CA::Elementary::STATE_ON) return (number & 2) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_OFF && midCenter.getState() == CA::Elementary::STATE_ON && midRight.getState() == CA::Elementary::STATE_OFF) return (number & 4) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_OFF && midCenter.getState() == CA::Elementary::STATE_ON && midRight.getState() == CA::Elementary::STATE_ON) return (number & 8) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_ON && midCenter.getState() == CA::Elementary::STATE_OFF && midRight.getState() == CA::Elementary::STATE_OFF) return (number & 16) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_ON && midCenter.getState() == CA::Elementary::STATE_OFF && midRight.getState() == CA::Elementary::STATE_ON) return (number & 32) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_ON && midCenter.getState() == CA::Elementary::STATE_ON && midRight.getState() == CA::Elementary::STATE_OFF) return (number & 64) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    if(midLeft.getState() == CA::Elementary::STATE_ON && midCenter.getState() == CA::Elementary::STATE_ON && midRight.getState() == CA::Elementary::STATE_ON) return (number & 128) ? CA::Elementary::STATE_ON : CA::Elementary::STATE_OFF;
    return CA::Elementary::STATE_OFF;
}