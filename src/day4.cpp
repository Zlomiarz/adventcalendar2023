#include "day4.hpp"
#include <fstream>
#include <algorithm>

#include <iostream>

int Day4::getResult(){
    int ret = 0;
    for (auto line:file){
        ret += processLine(line);
    }
    return ret;
}

int Day4::processLine(std::string line){
    auto setsStart = line.find(':');
    auto setsDelimiter = line.find('|');
    auto set1 = parseSet(line.substr(setsStart+1, setsDelimiter-setsStart-1));
    auto set2 = parseSet(line.substr(setsDelimiter+1));
    int count = 0;
    for (auto i:set1){
        if (std::find(set2.begin(), set2.end(), i) != set2.end()){
            count++;
        }
    }
    if (count == 0)
        return 0;
    return 0x1<<(count-1);
}

std::vector<int> Day4::parseSet(std::string str){
    std::vector<int> ret;
    auto strings = tokenize(str, ' ');
    for (auto s:strings)
        if (s.size()>0)
            ret.push_back(std::stoi(s));
    return ret;
}
