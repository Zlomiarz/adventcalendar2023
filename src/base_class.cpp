#include "base_class.hpp"

#include <fstream>

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

Base::Base(const std::string filename){
    loadFile(filename);
}

Base::Base(const std::vector<std::string> &content):file(content){}

void Base::loadFile(const std::string filename){
    std::ifstream in(filename);
    if (!in){
        throw std::runtime_error("File no found!");
    }
    while (in){
        std::string line;
        getline(in, line);
        if (line.size()>0)
            file.push_back(line);
    }
}

std::vector<std::string> Base::tokenize(std::string str, char delimiter){
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

std::vector<int> Base::tokenizeInt(std::string str, char delimiter){
    std::vector<int> ret;
    size_t start = 0;
    size_t pos;
    while (pos = str.find(delimiter, start), pos != std::string::npos){
        ret.push_back(std::stoi(trim(str.substr(start, pos-start))));
        start = pos+1;
    }
    ret.push_back(std::stoi(trim(str.substr(start))));
    return ret;
}