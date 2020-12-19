#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <fstream>

class CF1427B_ChessCheaterTest
    : public testing::TestWithParam<std::pair<std::string, std::string>>
{
};

TEST_P(CF1427B_ChessCheaterTest, ChessCheaterTest)
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
    CF1427B_ChessCheaterTests, CF1427B_ChessCheaterTest,
    ::testing::Values(std::make_pair("Codeforces/CF1427B/data/0_in.txt","Codeforces/CF1427B/data/0_out.txt"),
                      std::make_pair("Codeforces/CF1427B/data/1_in.txt","Codeforces/CF1427B/data/1_out.txt"),
                      std::make_pair("Codeforces/CF1427B/data/2_in.txt","Codeforces/CF1427B/data/2_out.txt"),
                      std::make_pair("Codeforces/CF1427B/data/3_in.txt","Codeforces/CF1427B/data/3_out.txt"),
                      std::make_pair("Codeforces/CF1427B/data/4_in.txt","Codeforces/CF1427B/data/4_out.txt"),
                      std::make_pair("Codeforces/CF1427B/data/5_in.txt","Codeforces/CF1427B/data/5_out.txt")));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
