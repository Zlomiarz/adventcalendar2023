#include "day2.hpp"

#include <iostream>

inline std::string ltrim(std::string s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

inline std::string rtrim(std::string s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string trim(std::string s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

int Day2::getResult(){
    int ret = 0;
    for (auto line:file){
        auto a = tokenize(line, ':');
        int game_number = std::stoi(a[0].substr(5));
        if (processGame(a[1])){
            ret += game_number;
            std::cout << game_number << "\n";
        }
    }
    return ret;
}

bool Day2::processGame(std::string game){
    auto rounds = tokenize(game, ';');
    for (auto round:rounds){
        if (!roundIsOK(round))
            return false;
    }
    return true;
}

bool Day2::roundIsOK(std::string round){
    const auto red_limit = 12;
    const auto green_limit = 13;
    const auto blue_limit = 14;

    auto colors = tokenize(round, ',');
    for (auto color:colors){
        auto p = tokenize(color, ' ');
        if (p[1] == "red" and std::stoi(p[0])>red_limit)
            return false;
        if (p[1] == "blue" and std::stoi(p[0])>blue_limit)
            return false;
        if (p[1] == "green" and std::stoi(p[0])>green_limit)
            return false;
    }
    return true;
}

std::vector<std::string> Day2::tokenize(std::string str, char delimiter){
    std::vector<std::string> ret;
    size_t start = 0;
    size_t pos;
    while (pos = str.find(delimiter, start), pos != std::string::npos){
        ret.push_back(trim(str.substr(start, pos-start)));
        start = pos+1;
    }
    ret.push_back(trim(str.substr(start)));
    return ret;
}
