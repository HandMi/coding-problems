#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP1_SumOfMultiplesOf3And5Test
    : public testing::TestWithParam<std::pair<int, long long>>
{
};

TEST_P(PEP1_SumOfMultiplesOf3And5Test, SumOfMultiplesOf3And5Test)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    auto result = SumOfMultiplesOf3And5(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP1_SumOfMultiplesOf3And5Tests, PEP1_SumOfMultiplesOf3And5Test,
    ::testing::Values(std::make_pair(2,0),
                      std::make_pair(4,3),
                      std::make_pair(6,8),
                      std::make_pair(10,23),
                      std::make_pair(100,2318),
                      std::make_pair(1000000001,233333334166666668)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}