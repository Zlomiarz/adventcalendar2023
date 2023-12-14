#include "day2.hpp"

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
