#pragma once

#include "base_class.hpp"

enum Direction{
    South, West, East, North
};

using Point2d = std::pair<int, int>;
using Shape2d = std::vector<Point2d>;

int calculateArea(Shape2d shape);
int calculateInteriorPoints(int area, int boundaryPoints);

class Day10:public Base{
public:
    Day10(const std::string filename):Base(filename){}
    Day10(const std::vector<std::string> &content):Base(content){}
    long getResult();
public:
    Shape2d getMapDirections(Point2d pos);
    Point2d findStartPos();
    Shape2d findLoop(Point2d start);
    long findLoopLength(Point2d start);
    long findLoopLength(Shape2d& stack);

    char getMapField(Point2d pos){
        return file[pos.second][pos.first];
    }
};
