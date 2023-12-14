#pragma once

#include "base_class.hpp"

#include <tuple>

class Day2:Base{
public:
    Day2(const std::string filename):Base(filename){};

    int getResult();
private:
    std::tuple<int, int, int> getNumberOfCubes(std::string round);
    int processGame(std::string game);
};
