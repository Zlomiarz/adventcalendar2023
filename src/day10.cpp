#include "day10.hpp"

#include <algorithm>

long Day10::getResult(){
    auto start = findStartPos();
    auto loop = findLoop(start);
    auto area = calculateArea(loop);
    return calculateInteriorPoints(area, loop.size());
}

Point2d Day10::findStartPos(){
    for (unsigned int y=0;y<file.size();++y){
        for (unsigned x=0;x<file[y].size();++x){
            if (file[y][x] == 'S')
                return std::make_pair(x, y);
        }
    }
    return std::make_pair(-1, -1);
}

Shape2d Day10::findLoop(Point2d start){
    Shape2d stack;
    stack.push_back(start);
    findLoopLength(stack);
    return stack;
}

long Day10::findLoopLength(Point2d start){
    Shape2d stack;
    stack.push_back(start);
    auto loopLenght = findLoopLength(stack);
    auto area = calculateArea(stack);
    return calculateInteriorPoints(area, loopLenght);
}

long Day10::findLoopLength(Shape2d &stack){
    auto pos = stack.back();
    auto directions = getMapDirections(pos);
    for (auto p:directions){
        auto c = getMapField(p);
        if (c == '.')
            continue;
        
        if (stack.size() > 1 && stack[stack.size()-2] == p)
            continue;
        if (c == 'S'){
            return stack.size() + 1;
        }
        stack.push_back(p);
        auto v = findLoopLength(stack);
        if (v != 0)
            return v;
        stack.pop_back();
           
    }
    return 0;
}

Shape2d Day10::getMapDirections(Point2d pos){
    Shape2d ret;
    switch (getMapField(pos)){
        case '|':
            ret.push_back(std::make_pair(pos.first, pos.second+1));
            ret.push_back(std::make_pair(pos.first, pos.second-1));
            break;
        case '-':
            ret.push_back(std::make_pair(pos.first+1, pos.second));
            ret.push_back(std::make_pair(pos.first-1, pos.second));
            break;
        case 'L':
            ret.push_back(std::make_pair(pos.first, pos.second-1));
            ret.push_back(std::make_pair(pos.first+1, pos.second));
            break;
        case 'J':
            ret.push_back(std::make_pair(pos.first, pos.second-1));
            ret.push_back(std::make_pair(pos.first-1, pos.second));
            break;
        case '7':
            ret.push_back(std::make_pair(pos.first, pos.second+1));
            ret.push_back(std::make_pair(pos.first-1, pos.second));
            break;
        case 'F':
            ret.push_back(std::make_pair(pos.first, pos.second+1));
            ret.push_back(std::make_pair(pos.first+1, pos.second));
            break;
        case 'S':
            {   
                auto p = std::make_pair(pos.first, pos.second+1);
                if (getMapField(p) == '|' || getMapField(p) == 'L' || getMapField(p) == 'J')
                    ret.push_back(p);
            }
            {   
                auto p = std::make_pair(pos.first, pos.second-1);
                if (getMapField(p) == '|' || getMapField(p) == '7' || getMapField(p) == 'F')
                    ret.push_back(p);
            }
            {   
            auto p = std::make_pair(pos.first+1, pos.second);
                if (getMapField(p) == '-' || getMapField(p) == '7' || getMapField(p) == 'J')
                    ret.push_back(p);
            }
            {
                auto p = std::make_pair(pos.first-1, pos.second);
                if (getMapField(p) == '-' || getMapField(p) == 'F' || getMapField(p) == 'L')
                    ret.push_back(p);
            }
            break;
        default:
            break;
    }
    return ret;
}

//https://en.wikipedia.org/wiki/Shoelace_formula
int calculateArea(Shape2d shape){
    if (shape.size()<3)
        return -1;

    shape.push_back(shape.front());
    int ret = 0;
    for (unsigned i=1;i<shape.size();i++){
        ret += -shape[i-1].first * -shape[i].second;
        ret -= -shape[i].first * -shape[i-1].second;
    }
    return std::abs(ret/2);
}

//https://en.wikipedia.org/wiki/Pick%27s_theorem
int calculateInteriorPoints(int area, int boundaryPoints){
    return area + 1 - boundaryPoints/2;
}