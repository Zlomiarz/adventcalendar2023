#pragma once

#include "base_class.hpp"

class Day2:Base{
public:
    Day2(const std::string filename):Base(filename){};

    int getResult();
private:
    std::vector<std::string> tokenize(std::string str, char delimiter);
    bool roundIsOK(std::string round);
    bool processGame(std::string game);
};
