#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP016_PowerDigitSumTest
    : public testing::TestWithParam<std::pair<int, int>>
{
};

TEST_P(PEP016_PowerDigitSumTest, PowerDigitSumTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    std::vector<std::string> powers{"1"};
    auto result = PowerDigitSum(n, powers);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP016_PowerDigitSumTests, PEP016_PowerDigitSumTest,
    ::testing::Values(std::make_pair(3,8),
                      std::make_pair(4,7),
                      std::make_pair(7,11)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
