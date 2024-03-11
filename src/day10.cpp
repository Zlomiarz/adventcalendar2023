#include "day10.hpp"

#include <algorithm>

long Day10::getResult(){
    auto start = findStartPos();
    auto loopLenght = findLoopLength(start);
    return loopLenght/2;
}

std::pair<int, int> Day10::findStartPos(){
    for (unsigned int y=0;y<file.size();++y){
        for (unsigned x=0;x<file[y].size();++x){
            if (file[y][x] == 'S')
                return std::make_pair(x, y);
        }
    }
    return std::make_pair(-1, -1);
}

long Day10::findLoopLength(std::pair<int, int> start){
    std::vector<std::pair<int, int>> stack;
    stack.push_back(start);
    return findLoopLength(stack);
}

long Day10::findLoopLength(std::vector<std::pair<int, int>> stack){
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

std::vector<std::pair<int, int>> Day10::getMapDirections(std::pair<int, int> pos){
    std::vector<std::pair<int, int>> ret;
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