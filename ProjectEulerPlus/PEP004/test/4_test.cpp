#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP004_LargestPalindromeProductTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP004_LargestPalindromeProductTest, LargestPalindromeProduct)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;

    auto result = LargestPalindromeProduct(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP004_LargestPalindromeProductTests, PEP004_LargestPalindromeProductTest,
    ::testing::Values(std::make_pair(2,0),
                      std::make_pair(101110,101101),
                      std::make_pair(800000,793397)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
