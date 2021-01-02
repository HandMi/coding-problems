#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP015_LatticePathTest
    : public testing::TestWithParam<
          std::pair<std::pair<std::uint32_t, std::uint32_t>, std::uint32_t>>
{
};

TEST_P(PEP015_LatticePathTest, LatticePathTest)
{
    auto input = GetParam().first;
    auto expected = GetParam().second;
    LatticePathCalculator lattice_path_calculator;
    lattice_path_calculator.CalculateLatticePaths(500, 500);
    auto result =
        lattice_path_calculator.GetLatticePath(input.first, input.second);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP015_LatticePathTests, PEP015_LatticePathTest,
    ::testing::Values(std::make_pair(std::make_pair(2,2),6),
                      std::make_pair(std::make_pair(3,2),10)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
