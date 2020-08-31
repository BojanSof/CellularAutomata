#ifndef STATE_HPP
#define STATE_HPP

#include <string>

namespace CA {

class State {
public:
   State();
   State(std::string v);
   State(const char *v);
   bool operator==(const State &s);

   const std::string &getValue() const { return value; }

   static const State OFF;
   static const State ON;
private:
   std::string value;
};

}

#endif //STATE_HPP