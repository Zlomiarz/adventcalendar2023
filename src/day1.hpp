#pragma once

#include "base_class.hpp"

class Day1:Base{
public:
    Day1(const std::string filename):Base(filename){}
    int getResult();
    int getResult2();
private:

    int getFirstDigit(const std::string str);
    int getLastDigit(const std::string str);
};
