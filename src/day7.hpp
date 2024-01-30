#pragma once

#include "base_class.hpp"
#include <map>

class Day7:Base{
public:
    using CardsAndBid = std::pair<std::string, int>;
    using CardsAndBidsCollection = std::vector<CardsAndBid>;
    Day7(const std::string filename):Base(filename){}
    long getResult();
private:
    CardsAndBidsCollection loadCardsAndBids();
    
    std::map<char, int> cardToValue{{'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5},
            {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}};

};
