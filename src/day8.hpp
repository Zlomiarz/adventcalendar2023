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
    class NavigationString{
        public:
        NavigationString(string s):navigation(s){}
        char getNext(){
            char c = navigation[index];
            index = (index+1)% navigation.size();
            return c;
        }
        private:
            string navigation;
            int index=0;
    };
    GraphType parseFile();
    Node parseLine(string s);

private:

};
