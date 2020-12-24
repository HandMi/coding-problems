#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP005_LCMTest : public testing::TestWithParam<std::pair<long, long long>>
{
};

TEST_P(PEP005_LCMTest, LCMTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    PrimeGenerator prime_generator(40);
    auto result = prime_generator.LCM(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP005_LCMTests, PEP005_LCMTest,
    ::testing::Values(std::make_pair(1,1),
                      std::make_pair(2,2),
                      std::make_pair(3,6),
                      std::make_pair(10,2520),
                      std::make_pair(11,27720),
                      std::make_pair(40,5342931457063200)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
