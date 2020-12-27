#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP009_PythagoreanTripletTest
    : public testing::TestWithParam<std::pair<long, long>>
{
};

TEST_P(PEP009_PythagoreanTripletTest, PythagoreanTripletTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    auto result = PythagoreanTriplet(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP009_PythagoreanTripletTests, PEP009_PythagoreanTripletTest,
    ::testing::Values(std::make_pair(1,-1),
                      std::make_pair(4,-1),
                      std::make_pair(11,-1),
                      std::make_pair(12,60),
                      std::make_pair(24,480),
                      std::make_pair(60,7500),
                      std::make_pair(198,235620),
                      std::make_pair(208,277680),
                      std::make_pair(378,1803060)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
