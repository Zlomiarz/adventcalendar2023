#include "day4.hpp"

#include <algorithm>

int Day4::getResult(){
    int ret = 0;
    std::deque<int> copies(file.size(), 1);
    for (auto line:file){
        ret += processLine(line, copies);
        copies.erase(copies.begin());
    }
    return ret;
}

int Day4::processLine(std::string line, std::deque<int> &copies){
    auto setsStart = line.find(':');
    auto setsDelimiter = line.find('|');
    auto set1 = parseSet(line.substr(setsStart+1, setsDelimiter-setsStart-1));
    auto set2 = parseSet(line.substr(setsDelimiter+1));
    int count = 0;
    int n = copies[0];
    for (auto i:set1){
        if (std::find(set2.begin(), set2.end(), i) != set2.end()){
            count++;
        }
    }
    for (int i=0;i<count;++i){
        copies[i+1] += n;
    }
    return n;
}

std::vector<int> Day4::parseSet(std::string str){
    /*std::vector<int> ret;
    auto strings = tokenize(str, ' ');
    for (auto s:strings)
        if (s.size()>0)
            ret.push_back(std::stoi(s));
    return ret;*/
    return tokenizeInt(str, ' ');
}
