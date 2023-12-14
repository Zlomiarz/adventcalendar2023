#include "day1.hpp"
#include <fstream>
#include <algorithm>

int Day1::getResult(){
    int ret = 0;
    for (auto &line:file){
        const auto d1 = *std::find_if(begin(line), end(line), static_cast<int(*)(int)>(std::isdigit));
        const auto d2 = *std::find_if(rbegin(line), rend(line), static_cast<int(*)(int)>(std::isdigit));
        ret += (d1-'0')*10+(d2-'0');
    }
    return ret;
}

int Day1::getResult2(){
    int ret = 0;
    for (auto &line:file){
        const auto d1 = getFirstDigit(line);
        const auto d2 = getLastDigit(line);
        ret += (d1)*10+(d2);
    }
    return ret;
}

int Day1::getFirstDigit(std::string str){
    std::vector<std::pair<std::string, int>> values = { {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    auto it1 = str.find_first_of("0123456789");
    int ret = 0;
    if (it1 == std::string::npos){
        it1 = str.size();
    } else {
        ret =  str[it1]-'0';
    }
    for (auto v:values){
        auto it = str.find(v.first);
        if (it != std::string::npos && it<it1) {
            it1 = it;
            ret = v.second;
        }
    }
    return ret;
}

int Day1::getLastDigit(std::string str){
    std::vector<std::pair<std::string, int>> values = { {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    auto it1 = str.find_last_of("0123456789");
    int ret = 0;
    if (it1 == std::string::npos){
        it1 = 0;
    } else {
        ret =  str[it1]-'0';
    }
    for (auto v:values){
        auto it = str.rfind(v.first);
        if (it != std::string::npos && it>it1) {
            it1 = it;
            ret = v.second;
        }
    }
    return ret;
}
