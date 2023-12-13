#pragma once

#include "base_class.hpp"

#include <vector>

class Day3:Base{
public:
    Day3(const std::string filename):Base(filename){}
    int getResult();
private:
    unsigned getNumberLength(unsigned v);
    std::vector<int> findAdjacentNumbers(int x, int y);
    std::pair<bool, int> findNumberStart(int x, int y);
    int getNumberAt(int x, int y);
};

