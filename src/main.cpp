#include <iostream>
#include <typeinfo>
#include "day1.hpp"
#include "day2.hpp"
#include "day3.hpp"
#include "day4.hpp"
#include "day5.hpp"
#include "day6.hpp"
#include "day7.hpp"
#include "day8.hpp"

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
    doJob<Day5>("input_day5.txt");
    doJob<Day6>("input_day6.txt");
    doJob<Day7>("input_day7.txt");
    doJob<Day8>("input_day8.txt");
    return 0;
}
