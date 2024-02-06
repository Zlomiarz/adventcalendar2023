#include "day8.hpp"

#include <algorithm>
#include <map>
#include <regex>

long Day8::getResult(){
    long ret = 0;
    NavigationString navigation(file[0]);
    auto graph = parseFile();
    string current = "AAA";
    while (current != "ZZZ"){
        auto edges = graph[current];
        if (navigation.getNext() == 'L')
            current = edges.first;
        else
            current = edges.second;
        ret++;
    }
    return ret;
}

Day8::GraphType Day8::parseFile(){
    GraphType ret;
    for (int i=1;i<file.size();i++){
        const auto [node, edges] = parseLine(file[i]);
        ret[node] = edges;
    }
    return ret;
}

Day8::Node Day8::parseLine(string s){
    const std::regex regex("(\\w+) = \\((\\w+)\\, (\\w+)\\)");
    std::smatch pieces_match;
    if (std::regex_match(s, pieces_match, regex)){
        if (pieces_match.size() ==4){
            string node = pieces_match[1].str();
            string edge1 = pieces_match[2].str();
            string edge2 = pieces_match[3].str();
            return {node, std::make_pair(edge1, edge2)};
        }
    }
    return {"", std::make_pair("", "")};
}
