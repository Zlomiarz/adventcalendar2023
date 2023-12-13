#include <iostream>
#include <typeinfo>
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"

template <typename T>
void doJob(const std::string &infile){
    try {
        T object(infile);
        std::cout << typeid(T).name() << ": " << object.getResult() << std::endl;
    }
    catch (...){
        std::cout << typeid(T).name() << ": something wrong!\n";
    }
}

int main(int, char**)
{
    doJob<Day1>("input_day1.txt");
    doJob<Day2>("input_day2.txt");
    doJob<Day3>("input_day3.txt");
    return 0;
}
