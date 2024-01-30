#include "day7.hpp"

#include <algorithm>

int getHandValue(std::string s);

int getHandValue(std::string s){
    std::map<char, int> counts;
    for (auto c:s){
        counts[c]++;
    }
    std::vector<int> histogram{0, 0, 0, 0, 0};
    for (auto p:counts){
        histogram[p.second-1]++;
    }
    if (histogram[4] == 1){
        return 7;
    }
    if (histogram[3] == 1){
        return 6;
    }
    if (histogram[2] == 1 && histogram[1] == 1){
        return 5;
    }
    if (histogram[2] == 1){
        return 4;
    }
    if (histogram[1] == 2){
        return 3;
    }
    if (histogram[1] == 1){
        return 2;
    }
    return 1;
}

long Day7::getResult(){
    int ret = 0;
    CardsAndBidsCollection collection = loadCardsAndBids();
    auto comp = [this](const CardsAndBid& a, const CardsAndBid& b){
        auto aValue = getHandValue(a.first);
        auto bValue = getHandValue(b.first);
        if (aValue != bValue)
            return aValue < bValue;
        for (unsigned i=0;i<a.first.size();i++)
            if (a.first[i] != b.first[i])
                return cardToValue[a.first[i]] < cardToValue[b.first[i]];
        return false;
    };
    std::sort(collection.begin(), collection.end(), comp);
    for (unsigned  i=0;i<collection.size();i++){
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