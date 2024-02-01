#include "day7.hpp"

#include <algorithm>
#include <map>

int getHandValue(std::string s){
    std::map<char, int> counts;
    int jokerCount = 0;
    for (auto c:s){
        counts[c]++;
        if (c == 'J')
            jokerCount++;
    }
    std::vector<int> histogram{0, 0, 0, 0, 0};
    for (auto p:counts){
        histogram[p.second-1]++;
    }

    auto getHistogramValue = [&histogram](){
        if (histogram[4] == 1){
            return Day7::FiveOfAKind;
        }
        if (histogram[3] == 1){
            return Day7::FourOfAKind;
        }
        if (histogram[2] == 1 && histogram[1] == 1){
            return Day7::FullHouse;
        }
        if (histogram[2] == 1){
            return Day7::ThreeOfAKind;
        }
        if ((histogram[1] == 2)){
            return Day7::TwoPairs;
        }
        if (histogram[1] == 1){
            return Day7::OnePair;
        }
        return Day7::HighCard;
    };
    auto histogramValue = getHistogramValue();
    if (jokerCount>0){
        if (histogramValue == Day7::FourOfAKind)
            return Day7::FiveOfAKind;
        if (histogramValue == Day7::FullHouse)
            return Day7::FiveOfAKind;
        if (histogramValue == Day7::ThreeOfAKind)
            return Day7::FourOfAKind;
        if (histogramValue == Day7::TwoPairs && jokerCount == 2)
            return Day7::FourOfAKind;
        if (histogramValue == Day7::TwoPairs && jokerCount == 1)
            return Day7::FullHouse;
        if (histogramValue == Day7::OnePair)
            return Day7::ThreeOfAKind;
        if (histogramValue == Day7::HighCard){
            return Day7::OnePair;
        }
    }
    return histogramValue;
}

long Day7::getResult(){
    long ret = 0;
    CardsAndBidsCollection collection = loadCardsAndBids();
    std::map<char, int> cardToValue{{'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5},
            {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 0}, {'Q', 11}, {'K', 12}, {'A', 13}};
    auto comp = [this, &cardToValue](const CardsAndBid& a, const CardsAndBid& b){
        auto aValue = getHandValue(a.first);
        auto bValue = getHandValue(b.first);
        if (aValue != bValue)
            return aValue < bValue;
        for (unsigned i=0;i<a.first.size();i++)
            if (a.first[i] != b.first[i])
                return cardToValue[a.first[i]] < cardToValue[b.first[i]];
        return true;
    };
    std::sort(collection.begin(), collection.end(), comp);
    for (unsigned long i=0;i<collection.size();i++){
        ret += collection[i].second * (i+1);
    }
    return ret;
}

Day7::CardsAndBidsCollection Day7::loadCardsAndBids(){
    CardsAndBidsCollection ret;    
    for (auto line:file){
        auto t = tokenize(line, ' ');
        ret.emplace_back(std::make_pair(t[0], std::stoi(t[1])));
    }
    return ret;
}