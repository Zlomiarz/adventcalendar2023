#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "src/day7.hpp"

TEST(Day7_HandValue, test_one_pair) {
    EXPECT_EQ(getHandValue("22KQ6"), Day7::OnePair);
    EXPECT_EQ(getHandValue("2J6A3"), Day7::OnePair);
}

TEST(Day7_HandValue, test_two_pair) {
    EXPECT_EQ(getHandValue("22K66"), Day7::TwoPairs);
    EXPECT_EQ(getHandValue("22363"), Day7::TwoPairs);
}

TEST(Day7_HandValue, test_three_of_a_kind) {
    EXPECT_EQ(getHandValue("22K26"), Day7::ThreeOfAKind);
    EXPECT_EQ(getHandValue("2J6AA"), Day7::ThreeOfAKind);
    EXPECT_EQ(getHandValue("2J6JA"), Day7::ThreeOfAKind);
}

TEST(Day7_HandValue, test_full_house) {
    EXPECT_EQ(getHandValue("22626"), Day7::FullHouse);
    EXPECT_EQ(getHandValue("6J6AA"), Day7::FullHouse);
}

TEST(Day7_HandValue, test_four_of_a_kind) {
    EXPECT_EQ(getHandValue("22K22"), Day7::FourOfAKind);
    EXPECT_EQ(getHandValue("AJ6AA"), Day7::FourOfAKind);
    EXPECT_EQ(getHandValue("3J9J3"), Day7::FourOfAKind);
    EXPECT_EQ(getHandValue("JJ7JA"), Day7::FourOfAKind);
}

TEST(Day7_HandValue, test_five_of_a_kind) {
    EXPECT_EQ(getHandValue("44444"), Day7::FiveOfAKind);
    EXPECT_EQ(getHandValue("JQQJQ"), Day7::FiveOfAKind);
    EXPECT_EQ(getHandValue("KJKJJ"), Day7::FiveOfAKind);
    EXPECT_EQ(getHandValue("JJ7JJ"), Day7::FiveOfAKind);
}
