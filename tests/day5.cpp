#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "src/day5.hpp"

TEST(Day5_Range, test_overlap) {
    Range r1{1, 4};
    Range r2{2, 5};
    Range r3{6, 9};
    Range r4{-3, 0};

    EXPECT_TRUE(r1.isOverlapping(r2));
    EXPECT_TRUE(r2.isOverlapping(r1));
    
    EXPECT_FALSE(r1.isOverlapping(r3));
    EXPECT_FALSE(r3.isOverlapping(r1));

    EXPECT_FALSE(r1.isOverlapping(r4));
    EXPECT_FALSE(r4.isOverlapping(r1));
}

TEST(Day5_RangeMapping, test_noOverlap) {
    RangeList list;
    list.addRange(RangeMapping(1, 3, 4));
    
    Range inRange(10, 5);
    auto ret = list.applyRangeMapping(inRange);
    EXPECT_EQ(ret.size(), 1);
    EXPECT_THAT(ret, ::testing::Contains(inRange));
}

TEST(Day5_RangeMapping, test_overlap1) {
    RangeList list;
    list.addRange(RangeMapping(10, 14, 20));
    
    auto ret = list.applyRangeMapping(Range (12, 13));
    EXPECT_EQ(ret.size(), 1);
    EXPECT_THAT(ret, ::testing::Contains(Range(22,23)));

    auto ret2 = list.applyRangeMapping(Range (10, 14));
    EXPECT_EQ(ret2.size(), 1);
    EXPECT_THAT(ret2, ::testing::Contains(Range(20,24)));

    auto ret3 = list.applyRangeMapping(Range (10, 12));
    EXPECT_EQ(ret3.size(), 1);
    EXPECT_THAT(ret3, ::testing::Contains(Range(20,22)));

    auto ret4 = list.applyRangeMapping(Range (14, 14));
    EXPECT_EQ(ret4.size(), 1);
    EXPECT_THAT(ret4, ::testing::Contains(Range(24,24)));
}

TEST(Day5_RangeMapping, test_overlap2) {
    RangeList list;
    list.addRange(RangeMapping(100, 109, 0));

    auto ret = list.applyRangeMapping(Range (95, 104));
    EXPECT_EQ(ret.size(), 2);
    EXPECT_THAT(ret, ::testing::Contains(Range(95, 99)));
    EXPECT_THAT(ret, ::testing::Contains(Range(0, 4)));

    auto ret2 = list.applyRangeMapping(Range (95, 100));
    EXPECT_EQ(ret2.size(), 2);
    EXPECT_THAT(ret2, ::testing::Contains(Range(95, 99)));
    EXPECT_THAT(ret2, ::testing::Contains(Range(0, 0)));

    list.addRange(RangeMapping(90, 99, 200));;

    auto ret3 = list.applyRangeMapping(Range (95, 105));
    EXPECT_EQ(ret3.size(), 2);
    EXPECT_THAT(ret3, ::testing::Contains(Range(205, 209)));
    EXPECT_THAT(ret3, ::testing::Contains(Range(0, 5)));
}

TEST(Day5_RangeMapping, test_overlap3) {
    RangeList list;
    list.addRange(RangeMapping(123, 169, 200));
    
    auto ret = list.applyRangeMapping(Range (150, 249));
    EXPECT_EQ(ret.size(), 2);
    EXPECT_THAT(ret, ::testing::Contains(Range(170, 249)));
    EXPECT_THAT(ret, ::testing::Contains(Range(227, 246)));

    list.addRange(RangeMapping(170, 200, 1000));

    auto ret2 = list.applyRangeMapping(Range (160, 179));
    EXPECT_EQ(ret2.size(), 2);
    EXPECT_THAT(ret2, ::testing::Contains(Range(1000, 1009)));
    EXPECT_THAT(ret2, ::testing::Contains(Range(237, 246)));

    auto ret3 = list.applyRangeMapping(Range(200, 210));
    EXPECT_EQ(ret3.size(), 2);
    EXPECT_THAT(ret3, ::testing::Contains(Range(201, 210)));
    EXPECT_THAT(ret3, ::testing::Contains(Range(1030, 1030)));
}

TEST(Day5_RangeMapping, test_overlap4) {
    RangeList list;
    list.addRange(RangeMapping(512, 550, 256));

    auto ret = list.applyRangeMapping(Range (500, 560));
    EXPECT_EQ(ret.size(), 3);
    EXPECT_EQ(ret[0].start, 500);
    EXPECT_EQ(ret[0].end, 511);
    EXPECT_EQ(ret[2].start, 256);
    EXPECT_EQ(ret[2].end, 294);
    EXPECT_EQ(ret[1].start, 551);
    EXPECT_EQ(ret[1].end, 560);
}

TEST(Day5_RangeMapping, test_data1) {
    RangeList list;
    list.addRange(RangeMapping(98, 99, 50));
    list.addRange(RangeMapping(50, 97, 52));

    auto ret = list.applyRangeMapping(Range(79, 92));
    EXPECT_THAT(ret, ::testing::Contains(Range(81, 94)));

    auto ret2 = list.applyRangeMapping(Range(55, 67));
    EXPECT_THAT(ret2, ::testing::Contains(Range(57, 69)));
}

TEST(Day5_RangeMapping, test_data2) {
    RangeList list;
    list.addRange(RangeMapping(45, 63, 81));
    list.addRange(RangeMapping(64, 76, 68));
    list.addRange(RangeMapping(77, 96, 45));

    auto ret = list.applyRangeMapping(Range(46, 49));
    EXPECT_THAT(ret, ::testing::Contains(Range(82, 85)));

    auto ret2 = list.applyRangeMapping(Range(54, 62));
    EXPECT_THAT(ret2, ::testing::Contains(Range(90, 98)));

    auto ret3 = list.applyRangeMapping(Range(74, 87));
    EXPECT_THAT(ret3, ::testing::Contains(Range(45, 55)));
    EXPECT_THAT(ret3, ::testing::Contains(Range(78, 80)));
}
