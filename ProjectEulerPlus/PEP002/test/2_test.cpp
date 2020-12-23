#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP002_GetNextFibonacciTest
    : public testing::TestWithParam<
          std::pair<std::pair<long long, long long>, long long>>
{
};

TEST_P(PEP002_GetNextFibonacciTest, GetNextFibonacciTest)
{
    auto fibonacci_pair = GetParam().first;
    auto expected = GetParam().second;
    GetNextFibonacci(fibonacci_pair.first, fibonacci_pair.second);
    EXPECT_EQ(fibonacci_pair.first, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP002_GetNextFibonacciTests, PEP002_GetNextFibonacciTest,
    ::testing::Values(std::make_pair(std::make_pair(2,1),3),
                      std::make_pair(std::make_pair(55,34),89)));
// clang-format on

class PEP002_ComputeEvenFibonacciSumTest
    : public testing::TestWithParam<
          std::pair<std::map<long long, long long>, std::vector<long long>>>
{
};

TEST_P(PEP002_ComputeEvenFibonacciSumTest, ComputeEvenFibonacciSumTest)
{
    auto test_cases = GetParam().first;
    auto expected = GetParam().second;
    ComputeEvenFibonacciSum(test_cases);
    auto it = test_cases.begin();
    for (auto i = 0U; i < expected.size(); ++i)
    {
        EXPECT_EQ((*it).second, expected[i]);
        ++it;
    }
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP002_ComputeEvenFibonacciSumTests, PEP002_ComputeEvenFibonacciSumTest,
    ::testing::Values(std::make_pair(std::map<long long,long long>{{10,0},{100,44}},std::vector<long long>{10,44})));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
