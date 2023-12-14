#pragma once

#include "base_class.hpp"

class Day4:Base{
public:
    Day4(const std::string filename):Base(filename){}
    int getResult();
private:
    int processLine(std::string line);
    std::vector<int> parseSet(std::string str);
};
