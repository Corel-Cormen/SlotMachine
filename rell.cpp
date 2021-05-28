#include "rell.h"

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

uint64_t timeSinceEpochMillisec();

// Constructor class Rell
// @param initList - initialization list showing of spin roll
template <typename T>
Rell<T>::Rell(std::initializer_list<T> initList) : rell(initList)
{

}

// function representing spinning of roll
// @return spin resultant vector
template <typename T>
std::vector<T> Rell<T>::spin(size_t sizeRoll) const
{
    if(sizeRoll > rell.size())
        throw std::invalid_argument("range size of roll is greater than rell size");

    return generateSpin(sizeRoll, randIndexFromDateSeed());
}

// function on basic MT algorithm draws a number
// @return number from (0, rell.size()-1)
template <typename T>
size_t Rell<T>::randIndexFromDateSeed() const
{
    static char control = 0;
    // config randomizing algorithm
    std::string seedString = std::to_string(timeSinceEpochMillisec()) + control;
    control++;
    std::seed_seq seed(seedString.begin(), seedString.end());
    std::mt19937 rng(seed);
    std::uniform_int_distribution<size_t> dist(0, rell.size()-1);

    return dist(rng);
}

// function get time (miliseconds) from system
uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

// function generate spinn score on roll
// @param sizeRoll - size of the resultant vector
//        index - random index from size roll
// @return spin resultant vector
template <typename T>
std::vector<T> Rell<T>::generateSpin(size_t sizeRoll, size_t index) const
{
    std::vector<T> result;

    size_t indexOutOfRange = 0;
    for(size_t i = 0; i < sizeRoll; i++)
    {
        if(index + i < rell.size()) {
            result.push_back(rell[index+i]);
        }
        else {
            result.push_back(rell[indexOutOfRange]);
            indexOutOfRange++;
        }
    }

    return result;
}

template class Rell<char>;
template class Rell<short>;
template class Rell<int>;
template class Rell<long int>;
template class Rell<long long int>;
