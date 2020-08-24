#ifndef STATE_HPP
#define STATE_HPP

namespace CA {

class State {
public:
   State();
   State(int v);
   bool operator==(const State &s);

   static const State OFF;
   static const State ON;
private:
   int value;
};

}

#endif //STATE_HPP