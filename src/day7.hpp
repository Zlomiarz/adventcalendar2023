#pragma once

#include "base_class.hpp"

int getHandValue(std::string s);

class Day7:Base{
public:
    using CardsAndBid = std::pair<std::string, int>;
    using CardsAndBidsCollection = std::vector<CardsAndBid>;
    Day7(const std::string filename):Base(filename){}
    long getResult();

    enum HandValue {HighCard = 1, OnePair = 2, TwoPairs = 3, ThreeOfAKind = 4, FullHouse = 5, FourOfAKind = 6, FiveOfAKind = 7};
private:
    CardsAndBidsCollection loadCardsAndBids();

};
