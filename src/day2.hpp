#pragma once

#include "base_class.hpp"

#include <tuple>

class Day2:Base{
public:
    Day2(const std::string filename):Base(filename){};

    int getResult();
private:
    std::vector<std::string> tokenize(std::string str, char delimiter);
    std::tuple<int, int, int> getNumberOfCubes(std::string round);
    int processGame(std::string game);
};
