#include "base_class.hpp"

#include <fstream>

Base::Base(const std::string filename){
    loadFile(filename);
}

void Base::loadFile(const std::string filename){
    std::ifstream in(filename);
    if (!in){
        throw std::runtime_error("File no found!");
    }
    while (in){
        std::string line;
        getline(in, line);
        if (line.size()>0)
            file.push_back(line);
    }
}
