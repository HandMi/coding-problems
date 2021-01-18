#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <fstream>

class PEP019_SundaysTest
    : public testing::TestWithParam<std::pair<std::string, std::string>>
{
};

TEST_P(PEP019_SundaysTest, SundaysTest)
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

INSTANTIATE_TEST_CASE_P(
    PEP019_SundaysTests, PEP019_SundaysTest,
    ::testing::Values(
        std::make_pair("ProjectEulerPlus/PEP019/data/0_in.txt",
                       "ProjectEulerPlus/PEP019/data/0_out.txt"),
        std::make_pair("ProjectEulerPlus/PEP019/data/1_in.txt",
                       "ProjectEulerPlus/PEP019/data/1_out.txt")));

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
