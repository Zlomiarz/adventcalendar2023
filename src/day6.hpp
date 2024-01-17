#pragma once

#include "base_class.hpp"

class Day6:Base{
public:
    Day6(const std::string filename):Base(filename){}
    long getResult();
private:
    std::vector<int> parseline(std::string);
    int numberOfWaysToWinRace(int, int);
};
