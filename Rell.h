#ifndef RELL_H
#define RELL_H

#include <vector>
#include <initializer_list>

template <typename T>
class Rell {
    const std::vector<T> rell;

public:
    Rell(std::initializer_list<T> initList);

    std::vector<T> spin(size_t sizeRoll) const;

private:
    size_t randIndexFromDateSeed() const;
    std::vector<T> generateSpin(size_t sizeRoll, size_t index) const;
};

#endif // RELL_H
