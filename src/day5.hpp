#pragma once

#include "base_class.hpp"

class Range{
public:
    Range(long start_, long end_):start(start_),end(end_){}
    bool isOverlapping(const Range& o) const{
        if (start>o.end)
            return false;
        if (end<o.start)
            return false;
        return true;
    }

    bool operator==(const Range& o) const{
        return start == o.start && end == o.end;
    }
    long start;
    long end;
};

class RangeMapping:public Range{
public:
    RangeMapping(long start_, long end_, long dest_):Range(start_, end_), destRangeStart(dest_){}

    long destRangeStart;
};

class RangeList{
public:
    void addRange(const RangeMapping& r){
        ranges.push_back(r);
    }

    std::vector<Range> applyRangeMapping(Range in){
        std::vector<Range> ret;
        for (auto r:ranges){
            if (r.isOverlapping(in)){
                if (r.start<=in.start){
                    if (r.end>=in.end){
                        auto lenght = in.end - in.start;
                        in.start = r.destRangeStart + in.start - r.start;
                        in.end = in.start+lenght;

                    } else {
                        Range t(in);
                        auto startOffset = in.start - r.start;
                        in.start = r.destRangeStart + startOffset;
                        in.end = r.destRangeStart + r.end - r.start;
                        t.start = r.end+1;
                        auto rest = applyRangeMapping(t);
                        ret.insert(ret.end(), rest.begin(), rest.end());
                    }
                } else {
                    if (r.end>=in.end){
                        Range t(in);
                        t.end = r.start -1;
                        in.end = r.destRangeStart + (in.end-r.start);
                        in.start = r.destRangeStart;
                        auto rest = applyRangeMapping(t);
                        ret.insert(ret.end(), rest.begin(), rest.end());
                    } else {
                        Range t1(in);
                        Range t2(in);
                        t1.end = r.start-1;
                        t2.start = r.end+1;
                        in.start = r.destRangeStart;
                        in.end = r.destRangeStart + (r.end - r.start);
                        auto rest1 = applyRangeMapping(t1);
                        auto rest2 = applyRangeMapping(t2);
                        ret.insert(ret.end(), rest1.begin(), rest1.end());
                        ret.insert(ret.end(), rest2.begin(), rest2.end());
                    }
                }
                break;
            }
        }
        ret.push_back(in);
        return ret;
    }

private:
    std::vector<RangeMapping> ranges;
};

class Day5:Base{
public:
    Day5(const std::string filename):Base(filename){}
    long getResult();
private:
    std::vector<Range> getSeeds(std::string str);
    int findRangeMappingEnd(int begin);
    RangeList loadRangeMappings(int begin, int end);

    std::vector<Range> applyMapping(std::vector<Range> seeds, RangeList rangeList);
};
