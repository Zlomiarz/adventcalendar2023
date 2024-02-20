#include "day9.hpp"

#include <algorithm>
#include <map>
#include <regex>

long Day9::getResult(){
    long ret = 0;
    for (const auto&line:file){
        ret += calculateValue(line); 
    }
    return ret;
}

long Day9::calculateValue(const std::string& line){
    auto values = tokenizeInt(line, ' ');
    return values.front() - calculateValue(values);
}

long Day9::calculateValue(const std::vector<int>& values){
    std::vector<int> calculated;
    for (unsigned i=1;i<values.size();++i){
        calculated.push_back(values[i] - values[i-1]);
    }
    if (std::any_of(calculated.begin(), calculated.end(), [](int i){ return i != 0;})){
        auto v = calculateValue(calculated);
        return calculated.front() - v;
    }
    
    return 0;

}

