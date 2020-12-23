#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <fstream>

class AOC20_03_2_TobogganTrajectoryTest
    : public testing::TestWithParam<std::pair<std::string, std::string>>
{
};

TEST_P(AOC20_03_2_TobogganTrajectoryTest, TobogganTrajectoryTest)
{
    auto input_file = GetParam().first;
    auto expected_file = GetParam().second;
    std::ifstream input_ifs(input_file);
    std::ifstream expected_ifs(expected_file);
    std::stringstream output;

    Solve(input_ifs, output);

    for (std::string expected_line; std::getline(expected_ifs, expected_line);)
    {
        std::string output_line;
        std::getline(output, output_line);
        EXPECT_EQ(output_line, expected_line);
    }
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    AOC20_03_2_TobogganTrajectoryTests, AOC20_03_2_TobogganTrajectoryTest,
    ::testing::Values(std::make_pair("AdventOfCode/2020/03/2/data/0_in.txt","AdventOfCode/2020/03/2/data/0_out.txt")));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
