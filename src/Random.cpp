#include <Random.hpp>

#ifdef __linux__
CA::Random::Random() : m_randomEngine(std::random_device()()){}

#elif __WIN32
CA::Random::Random() : m_randomEngine(srand(time(nullptr))){}

#endif

CA::Random::~Random() {}

unsigned int CA::Random::randUInt(unsigned int low, unsigned int high){
    std::uniform_int_distribution<unsigned int> dist(low, high);
    return dist(m_randomEngine);
}

unsigned int CA::Random::randUInt(unsigned int high){
    std::uniform_int_distribution<unsigned int> dist(0, high);
    return dist(m_randomEngine);
}
