#pragma once

#include "base_class.hpp"

enum Direction{
    South, West, East, North
};

class Day10:public Base{
public:
    Day10(const std::string filename):Base(filename){}
    long getResult();
private:
    std::vector<std::pair<int, int>> getMapDirections(std::pair<int, int> pos);
    std::pair<int, int> findStartPos();
    long findLoopLength(std::pair<int, int> start);
    long findLoopLength(std::vector<std::pair<int, int>> stack);

    char getMapField(std::pair<int, int> pos){
        return file[pos.second][pos.first];
    }
};
