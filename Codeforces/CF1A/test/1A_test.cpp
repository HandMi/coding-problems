#include "main.h"
#include "gtest/gtest.h"

class CF1A_ComputeFlagstonesTest
    : public testing::TestWithParam<std::tuple<std::array<int, 3>, int>>
{
};

TEST_P(CF1A_ComputeFlagstonesTest, PredefinedTests)
{
    auto parameters = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());

    EXPECT_EQ(ComputeFlagstones(parameters[0], parameters[1], parameters[2]),
              expected);
}

INSTANTIATE_TEST_CASE_P(
    CF1A_ComputeFlagstonesTests, CF1A_ComputeFlagstonesTest,
    ::testing::Values(std::make_tuple(std::array<int, 3>{6, 6, 4}, 4ll)));

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
