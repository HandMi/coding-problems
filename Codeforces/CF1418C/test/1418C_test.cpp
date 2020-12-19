#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1418C_CountSkipsTest
    : public testing::TestWithParam<std::pair<std::vector<int>, int>>
{
};

TEST_P(CF1418C_CountSkipsTest, CalculateSkips)
{
    auto bosses = GetParam().first;
    auto expected = GetParam().second;
    auto result = CalculateSkips(bosses);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
    CF1418C_CountSkipsTests, CF1418C_CountSkipsTest,
    ::testing::Values(std::make_pair(std::vector<int>{1, 0, 1, 1, 0, 1, 1, 1},
                                     2),
                      std::make_pair(std::vector<int>{1, 1, 1, 1, 0}, 2),
                      std::make_pair(std::vector<int>{1, 1, 1, 1, 0, 0, 1}, 2),
                      std::make_pair(std::vector<int>{1, 1, 1, 1, 1, 1}, 2),
                      std::make_pair(std::vector<int>{1}, 1),
                      std::make_pair(std::vector<int>{0}, 0)));

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}