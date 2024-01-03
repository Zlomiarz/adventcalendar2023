#pragma once

#include "base_class.hpp"
#include <deque>

class Range{
public:
    Range(long startFrom_, long length_, long startTo_):startFrom(startFrom_), length(length_), startTo(startTo_){}
    bool inRange(long v){
        if (v<startFrom)
            return false;
        if (v>startFrom+length)
            return false;
        return true;
    }
    long mapValue(long v){
        if (inRange(v)){
            return startTo+(v-startFrom);
        }
        return v;
    }
private:
    long startFrom;
    long length;
    long startTo;
};

class RangeList{
public:
    void addRange(const Range& r){
        ranges.push_back(r);
    }
    long mapValue(long v){
        for (auto &r:ranges){
            if (r.inRange(v)){
                v = r.mapValue(v);
                return v;
            }
        }
        return v;
    }
private:
    std::vector<Range> ranges;
};

class Day5:Base{
public:
    Day5(const std::string filename):Base(filename){}
    long getResult();
private:
    std::vector<long> getSeeds(std::string str);
    int findRangeEnd(int begin);
    RangeList loadRanges(int begin, int end);

    void applyRangeToSeeds(std::vector<long>& seeds, RangeList rangeList);
};
