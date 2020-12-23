#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP036_DoubleBasePalindromesTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP036_DoubleBasePalindromesTest, DoubleBasePalindromes)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;

    PalindromeGenerator palindrome_generator;
    palindrome_generator.Generate(1000000);

    auto result = palindrome_generator.SumDoubleBase(n, 2);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP036_DoubleBasePalindromesTests, PEP036_DoubleBasePalindromesTest,
    ::testing::Values(std::make_pair(10,25)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
