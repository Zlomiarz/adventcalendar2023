#include "day3.hpp"

int Day3::getResult(){
    int ret = 0;
    for (unsigned y=0;y<file.size();++y)
        for (unsigned x=0;x<file[y].size();++x)
        {
            if (file[y][x] == '*')
            {
                auto values = findAdjacentNumbers(x, y);
                if (values.size() == 2){
                    ret += values[0]*values[1];
                }
            }
        }
    return ret;
}

unsigned Day3::getNumberLength(unsigned v){
    unsigned ret = 0;
    while(v>0){
        ret++;
        v /= 10;
    }
    return ret;
}

std::vector<int> Day3::findAdjacentNumbers(int x, int y){
    std::vector<int> ret;
    auto addNumberToVector = [&ret,this](int tx, int ty) {
        if (tx<0)
            return;
        if (ty<0)
            return;
        if (ty>=(int)file.size())
            return;
        if (tx>=(int)file[ty].size())
            return;
        auto res = findNumberStart(tx, ty);
        if (res.first)
            ret.push_back(getNumberAt(res.second, ty));
    };
    addNumberToVector(x-1, y);
    addNumberToVector(x+1, y);
    if (y-1>=0){
        if (isdigit(file[y-1][x])){
            addNumberToVector(x, y-1);
        } else {
            addNumberToVector(x-1, y-1);
            addNumberToVector(x+1, y-1);
        }
    }
    if (y+1<(int)file.size()){
        if (isdigit(file[y+1][x])){
            addNumberToVector(x, y+1);
        } else {
            addNumberToVector(x-1, y+1);
            addNumberToVector(x+1, y+1);
        }
    }
    return ret;
}

std::pair<bool, int> Day3::findNumberStart(int x, int y){
    if (!isdigit(file[y][x]))
        return std::make_pair(false, x);
    while (x>0 && isdigit(file[y][x-1]))
        x--;
    return std::make_pair(true, x);
}

int Day3::getNumberAt(int x, int y){
    return std::stoi(file[y].substr(x));
}
