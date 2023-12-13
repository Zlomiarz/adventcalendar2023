#pragma once

#include "base_class.hpp"

class Day3:Base{
public:
    Day3(const std::string filename):Base(filename){}
    int getResult();
private:
    unsigned getNumberLength(unsigned v);
    bool isAdjacent(int x, int y, unsigned len);
};

