#include <iostream>
#include "day1.hpp"
#include "day2.hpp"

int main(int, char**)
{
    try{
        Day1 day1("input_day1.txt");
        std::cout << day1.getResult2() << std::endl;
    }
    catch (...){
        std::cout << "Day1: something wrong!\n";
    }
	return 0;
}
