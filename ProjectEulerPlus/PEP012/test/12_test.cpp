#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP012_HighlyDivisibleTriangularNumberTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP012_HighlyDivisibleTriangularNumberTest,
       HighlyDivisibleTriangularNumberTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    Factorizer factorizer(2);
    auto result = factorizer.HighlyDivisibleTriangularNumber(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP012_HighlyDivisibleTriangularNumberTests, PEP012_HighlyDivisibleTriangularNumberTest,
    ::testing::Values(std::make_pair(1,3),
                      std::make_pair(2,6),
                      std::make_pair(3,6),
                      std::make_pair(4,28),
                      std::make_pair(8,36),
                      std::make_pair(9,120),
                      std::make_pair(15,120),
                      std::make_pair(1000,842161320)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
