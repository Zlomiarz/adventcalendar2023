#include "day3.hpp"

int Day3::getResult(){
    int ret = 0;
    for (unsigned y=0;y<file.size();++y)
        for (unsigned x=0;x<file[y].size();++x)
        {
            if (std::isdigit(file[y][x]))
            {
                auto v = std::stoi(file[y].substr(x));
                auto len = getNumberLength(v);
                if (isAdjacent(x, y, len))
                    ret += v;
                x += len;
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

bool Day3::isAdjacent(int x, int y, unsigned len){
    int x1 = std::max(x-1, 0);
    int x2 = std::min<int>(x+len, file[y].size()-1);
    int y1 = std::max(y-1, 0);
    int y2 = std::min<int>(y+1, file.size()-1);
    for(int iy=y1;iy<=y2;++iy)
        for(int ix=x1;ix<=x2;++ix)
            if (file[iy][ix] != '.' && std::ispunct(file[iy][ix]))
                return true;

    return false;
}
