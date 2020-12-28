#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP010_PrimeSumTest
    : public testing::TestWithParam<std::pair<long, long long>>
{
};

TEST_P(PEP010_PrimeSumTest, PrimeSumTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    PrimeGenerator prime_generator(200);
    auto result = prime_generator.SumPrimes(n);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(PEP010_PrimeSumTests, PEP010_PrimeSumTest,
                        ::testing::Values(std::make_pair(0, 0),
                                          std::make_pair(1, 0),
                                          std::make_pair(2, 2),
                                          std::make_pair(5, 10),
                                          std::make_pair(10, 17)));

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
