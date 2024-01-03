#include "day5.hpp"

#include <algorithm>

long Day5::getResult(){
    std::vector<long> seeds;
    auto t = tokenize(file[0], ':');
    seeds = getSeeds(t[1]);
    unsigned i = 2;
    while (i < file.size()){

        long end = findRangeEnd(i);
        auto rangeList = loadRanges(i+1, end);
        applyRangeToSeeds(seeds, rangeList);
        i = end+1;
    }
    std::sort(seeds.begin(), seeds.end());
    return seeds[0];
}

std::vector<long> Day5::getSeeds(std::string str){
    std::vector<long> ret;
    for (auto t:tokenize(str, ' ')){
        if (t.size()>0)
            ret.push_back(std::stol(t));
    }
    return ret;
}

int Day5::findRangeEnd(int begin){
    for (unsigned i=begin;i<file.size();++i){
        if (!std::isdigit(file[i][0]))
            return i;
    }
    return file.size();
}

RangeList Day5::loadRanges(int begin, int end){
    RangeList ret;
    for (int i=begin;i<end;++i){
        auto t = tokenize(file[i], ' ');
        if (t.size() == 3){
            ret.addRange(Range(std::stol(t[1]), std::stol(t[2]), std::stol(t[0])));
        }
    }
    return ret;
}

void Day5::applyRangeToSeeds(std::vector<long>& seeds, RangeList rangeList){
    for (auto& s:seeds){
        auto t = rangeList.mapValue(s);
        s = t;
    }
}

