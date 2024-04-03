#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "src/day10.hpp"

TEST(Day10_areaCalculation, testEmptyShape) {
    Shape2d shape{};
    EXPECT_EQ(calculateArea(shape), -1);
}

TEST(Day10_areaCalculation, testTriangle) {
    Shape2d shape{{1, 1}, {5, 1}, {5, 5}, {1, 5}};
    EXPECT_EQ(calculateArea(shape), 16);
}

TEST(Day10_areaCalculation, testSimpleSquare) {
    Shape2d shape{{1, 1}, {5, 1}, {5, 5}, {1, 5}};
    EXPECT_EQ(calculateArea(shape), 16);
}
