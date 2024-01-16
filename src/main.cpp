#include <iostream>
#include <typeinfo>
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "day5.hpp"

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
    doJob<Day4>("input_day4.txt");
    doJob<Day5>("test_day5.txt");
    return 0;
}
