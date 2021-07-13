#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <fstream>

class CF0463C_BishopsTest
    : public testing::TestWithParam<std::pair<std::string, std::string>>
{
};

TEST_P(CF0463C_BishopsTest, BishopsTest)
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
    CF0463C_BishopsTests, CF0463C_BishopsTest,
    ::testing::Values(std::make_pair("Codeforces/CF0463C/data/0_in.txt","Codeforces/CF0463C/data/0_out.txt")));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
