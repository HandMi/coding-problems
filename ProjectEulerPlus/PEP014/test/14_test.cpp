#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP014_LongestCollatzTest
    : public testing::TestWithParam<std::pair<std::uint64_t, std::uint64_t>>
{
};

TEST_P(PEP014_LongestCollatzTest, LongestCollatzTest)
{
    auto input = GetParam().first;
    auto expected = GetParam().second;
    CollatzChains collatz_chains;
    collatz_chains.ComputeCollatzChains(50000U);
    const auto output = collatz_chains.LongestCollatz(input);
    EXPECT_EQ(output, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP014_LongestCollatzTests, PEP014_LongestCollatzTest,
    ::testing::Values(std::make_pair(10,9),
                      std::make_pair(15,9),
                      std::make_pair(20,19)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
