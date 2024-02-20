#pragma once

#include "base_class.hpp"

class Day9:public Base{
public:
    Day9(const std::string filename):Base(filename){}
    long getResult();
private:
    long calculateValue(const std::string& line);
    long calculateValue(const std::vector<int>& values);
};
