#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP007_NthPrimeTest
    : public testing::TestWithParam<std::pair<long, long long>>
{
};

TEST_P(PEP007_NthPrimeTest, NthPrimeTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    PrimeGenerator prime_generator(200);
    auto result = prime_generator.GetPrime(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP007_NthPrimeTests, PEP007_NthPrimeTest,
    ::testing::Values(std::make_pair(3,5),
                      std::make_pair(6,13),
                      std::make_pair(109,599)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
