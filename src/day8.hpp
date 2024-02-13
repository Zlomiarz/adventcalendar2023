#pragma once

#include "base_class.hpp"

#include <map>
using std::string;
using std::map;
using std::pair;

class Day8:public Base{
public:
    Day8(const std::string filename):Base(filename){}
    long getResult();
    
    using Node=std::tuple<string, std::pair<string, string>>;
    using GraphType=map<string, pair<string, string>>;

private:
    class NavigationString{
        public:
        NavigationString(string s):navigation(s){}
        char getNext(){
            char c = navigation[index];
            index = (index+1)% navigation.size();
            return c;
        }
        void reset(){
            index = 0;
        }
        private:
            string navigation;
            int index=0;
    };
    
    long calculateDistanceToZNode(GraphType graph, string startPoint, NavigationString navigation);

    GraphType parseFile();
    Node parseLine(string s);
    std::vector<string> startNodes;
};
