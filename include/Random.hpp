#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <ctime>
#include <random>

namespace CA{

class Random{
public:
    Random();
    ~Random();
    unsigned int randUInt(unsigned int low, unsigned int high);
    unsigned int randUInt(unsigned int high);
private:
    std::mt19937 m_randomEngine;
};

}

#endif //RANDOM_HPP
