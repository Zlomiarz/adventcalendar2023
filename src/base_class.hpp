#pragma once

#include <string>
#include <vector>
class Base{
public:
    Base(const std::string filename);
protected:
    void loadFile(const std::string filename);
    std::vector<std::string> tokenize(std::string str, char delimiter);
    std::vector<int> tokenizeInt(std::string str, char delimiter);
    std::vector<std::string> file;
};
