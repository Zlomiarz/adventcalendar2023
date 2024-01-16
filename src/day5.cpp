#include "day5.hpp"

#include <algorithm>

long Day5::getResult(){
    auto t = tokenize(file[0], ':');
    auto seeds = getSeeds(t[1]);
    unsigned i = 2;
    while (i < file.size()){

        long end = findRangeMappingEnd(i);
        auto rangeList = loadRangeMappings(i, end);
        seeds = applyMapping(seeds, rangeList);
        i = end+1;
    }
    std::sort(seeds.begin(), seeds.end(), [](const auto &o1, const auto &o2) -> bool{
        return o1.start < o2.start;
    });

    return seeds[0].start;
}

std::vector<Range> Day5::getSeeds(std::string str){
    std::vector<Range> ret;
    auto tokens = tokenize(str, ' ');
    for (auto i=0u;i<tokens.size();i+=2){
        auto start = std::stol(tokens[i]);
        auto len = std::stol(tokens[i+1]);
        ret.push_back(Range(start, start+len-1));
    }
    return ret;
}

int Day5::findRangeMappingEnd(int begin){
    for (unsigned i=begin;i<file.size();++i){
        if (!std::isdigit(file[i][0]))
            return i;
    }
    return file.size();
}

RangeList Day5::loadRangeMappings(int begin, int end){
    RangeList ret;
    for (int i=begin;i<end;++i){
        auto t = tokenize(file[i], ' ');
        if (t.size() == 3){
            long start = std::stol(t[1]);
            long lenght = std::stol(t[2]);
            long destStart = std::stol(t[0]);
            ret.addRange(RangeMapping(start, start+lenght-1, destStart));
        }
    }
    return ret;
}

std::vector<Range> Day5::applyMapping(std::vector<Range> seeds, RangeList rangeList){
    std::vector<Range> ret;
    for (auto s:seeds){
        auto t = rangeList.applyRangeMapping(s);
        ret.insert(ret.end(), t.begin(), t.end());
    }
    return ret;
}

