#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP003_LargestPrimeFactorTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP003_LargestPrimeFactorTest, LargestPrimeFactorTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    Factorizer factorizer(2);
    auto result = factorizer.LargestPrimeFactor(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP003_LargestPrimeFactorTests, PEP003_LargestPrimeFactorTest,
    ::testing::Values(std::make_pair(0,0),
                      std::make_pair(1,1),
                      std::make_pair(10,5),
                      std::make_pair(17,17),
                      std::make_pair(18,3),
                      std::make_pair(20,5),
                      std::make_pair(140,7),
                      std::make_pair(13195,29),
                      std::make_pair(1000000000000,5),
                      std::make_pair(999999999989,999999999989)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
