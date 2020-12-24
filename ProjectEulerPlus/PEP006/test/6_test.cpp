#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP006_SumSquareDifferenceTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP006_SumSquareDifferenceTest, SumSquareDifferenceTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    auto result = SumSquareDifference(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP006_SumSquareDifferenceTests, PEP006_SumSquareDifferenceTest,
    ::testing::Values(std::make_pair(1,0),
                      std::make_pair(3,22),
                      std::make_pair(10,2640)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
