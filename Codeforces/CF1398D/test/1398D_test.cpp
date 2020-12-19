#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1398D_CalculateTotalAreaTest
    : public testing::TestWithParam<std::pair<Sticks, long>>
{
};

TEST_P(CF1398D_CalculateTotalAreaTest, CalculateTotalArea)
{
    auto sticks = GetParam().first;
    auto expected = GetParam().second;
    auto result = CalculateTotalArea(sticks);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF1398D_CalculateTotalAreaTests, CF1398D_CalculateTotalAreaTest,
    ::testing::Values(std::make_pair(Sticks{{3},{4},{5}}, 20),
                      std::make_pair(Sticks{{9, 5},{1},{2, 8, 5}}, 99),
                      std::make_pair(Sticks{{3},{3},{2, 2}}, 12),
                      std::make_pair(Sticks{{5, 2},{4, 1},{4, 3}}, 34),
                      std::make_pair(Sticks{{5, 2},{4, 3},{4, 1}}, 34),
                      std::make_pair(Sticks{{4, 3},{5, 2},{4, 1}}, 34),
                      std::make_pair(Sticks{{4, 3},{4, 1},{5, 2}}, 34),
                      std::make_pair(Sticks{{11, 7, 20, 15, 19, 14, 2, 4, 13, 14},{8},{11}}, 372),
                      std::make_pair(Sticks{{3, 10},{6, 9},{10, 9}}, 199),
                      std::make_pair(Sticks{{44, 13, 2, 24, 56, 74, 72, 4, 87, 98, 43, 4, 17, 30, 82, 8},
                                            {31, 6, 76, 32, 88, 37, 19, 64, 44, 55, 18, 67, 72, 75, 10, 45, 47, 89, 33, 100, 76, 1, 58, 38, 34, 38},
                                            {31, 37, 82, 36, 67, 86, 81, 6}}, 73851)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
