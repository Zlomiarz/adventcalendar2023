#include "day6.hpp"

#include <algorithm>
#include <iostream>
long Day6::getResult(){
    int ret = 1;
    auto times = parseline(file[0]);
    auto distances = parseline(file[1]);
    for (unsigned i=0;i<times.size();++i){
        ret *= numberOfWaysToWinRace(times[i], distances[i]);
    }
    return ret;
}

std::vector<int> Day6::parseline(std::string str){
    std::vector<int> ret;
    auto temp = tokenize(str, ':');
    auto tokens = tokenize(temp[1], ' ');
    for (auto t:tokens){
        if (t.size()>0)
            ret.push_back(std::stoi(t));
        
    }
    return ret;
}

int Day6::numberOfWaysToWinRace(int time, int record){
    int ret = 0;
    for (int accelerationTime=1;accelerationTime<time;++accelerationTime){
        int distance = accelerationTime*(time-accelerationTime);
        if (distance>record)
            ret++;
    }
    return ret;
}
