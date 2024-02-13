#include "day8.hpp"

#include <algorithm>
#include <map>
#include <regex>
#include <iostream>

template <typename T>
T GDC(T a, T b){
    T p;
  	while(b!=0){
    	p = b;
    	b = a%b;
    	a = p;  
  	}
    return a;
}

template <typename T>
T LCM(T a, T b){
    return a*b/GDC(a, b);
}

template <typename T>
T LCM(const std::vector<T> &v){
    if (v.size() == 0)
        return T();
    if (v.size() == 1)
        return v[0];
    int a = v[0];
    for (int i=1;i<v.size();i++){
        a = LCM(a, v[i]);
    }
    return a;
}

long Day8::getResult(){
    NavigationString navigation(file[0]);
    auto graph = parseFile();

    long a = calculateDistanceToZNode(graph, startNodes[0], navigation);
    for (unsigned i=1;i<startNodes.size();i++){
        navigation.reset();
        a = LCM(a, calculateDistanceToZNode(graph, startNodes[i], navigation));
    }
    return a;
}

Day8::GraphType Day8::parseFile(){
    GraphType ret;
    for (unsigned i=1;i<file.size();i++){
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
            if (node[2] == 'A')
                startNodes.push_back(node);
            return {node, std::make_pair(edge1, edge2)};
        }
    }
    return {"", std::make_pair("", "")};
}


long Day8::calculateDistanceToZNode(GraphType graph, string startPoint, NavigationString navigation){
    string current = startPoint;
    long count = 0;
    do{
        auto edges = graph[current];
        if (navigation.getNext() == 'L')
            current = edges.first;
        else
            current = edges.second;
        count++;
    } while(current[2] != 'Z');
    return count;
}