#ifndef STATE_HPP
#define STATE_HPP

#include <string>

namespace CA {

class State {
public:
   State();
   State(std::string v);
   State(const char *v);
   bool operator==(const CA::State &s) const;
   const std::string &getValue() const { return value; }
private:
   std::string value;
};

//comparator function object class for std::map
struct StateCompare {
   bool operator() (const State &s1, const State &s2) const;
};

}

#endif //STATE_HPP