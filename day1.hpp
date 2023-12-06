#pragma once

#include <string>
#include <vector>

class Day1{
public:
    Day1(const std::string& filename);
    int getResult();
    int getResult2();
private:
    void loadFile(const std::string& filename);
    int getFirstDigit(std::string str);
    int getLastDigit(std::string str);

    std::vector<std::string> file;
};
