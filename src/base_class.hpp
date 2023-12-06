#pragma once

#include <string>
#include <vector>
class Base{
public:
    Base(const std::string filename);
protected:
    void loadFile(const std::string filename);

    std::vector<std::string> file;
};
