#include <iostream>
#include "day1.hpp"
#include "day2.hpp"

int main(int, char**)
{
    try{
        Day1 day1("input_day1.txt");
        std::cout << "Day1: " << day1.getResult2() << std::endl;
    }
    catch (...){
        std::cout << "Day1: something wrong!\n";
    }
    try{
        Day2 day2("input_day2.txt");
        std::cout << "Day2: " << day2.getResult() << std::endl;
    }
    catch (...){
        std::cout << "Day2: something wrong!\n";
    }
    return 0;
}
