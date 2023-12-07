#include "day2.hpp"

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
        ret += processGame(a[1]);
    }
    return ret;
}

int Day2::processGame(std::string game){
    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;
    auto rounds = tokenize(game, ';');
    for (auto round:rounds){
        const auto [red, green, blue] = getNumberOfCubes(round);
        max_red = std::max(max_red, red);
        max_green = std::max(max_green, green);
        max_blue = std::max(max_blue, blue);
    }
    return max_red*max_green*max_blue;
}

std::tuple<int, int, int> Day2::getNumberOfCubes(std::string round){
    int red = 0;
    int blue = 0;
    int green = 0;
    auto colors = tokenize(round, ',');
    for (auto color:colors){
        auto p = tokenize(color, ' ');
        if (p[1] == "red")
            red = std::stoi(p[0]);
        if (p[1] == "blue")
            blue = std::stoi(p[0]);
        if (p[1] == "green")
            green = std::stoi(p[0]);
    }
    return std::make_tuple(red, green, blue);
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
