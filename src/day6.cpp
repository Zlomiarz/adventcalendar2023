#include "day6.hpp"

#include <algorithm>

long Day6::getResult(){
    int ret = 1;
    auto time = parseline(file[0]);
    auto distance = parseline(file[1]);
    ret = numberOfWaysToWinRace(time, distance);
    return ret;
}

long Day6::parseline(std::string in){
    auto temp = tokenize(in, ':');
    auto str = temp[1];
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    return std::stol(str);
}

int Day6::numberOfWaysToWinRace(long time, long record){
    int ret = 0;
    for (long accelerationTime=1;accelerationTime<time;++accelerationTime){
        long distance = accelerationTime*(time-accelerationTime);
        if (distance>record)
            ret++;
    }
    return ret;
}
