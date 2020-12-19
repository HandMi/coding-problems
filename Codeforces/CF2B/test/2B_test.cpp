#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF2B_CountFactorTest
    : public testing::TestWithParam<std::pair<int, std::pair<int, int>>>
{
};

TEST_P(CF2B_CountFactorTest, CountCorrectFactors)
{
    const auto parameter = GetParam().first;
    const auto expected = GetParam().second;
    auto result = CountFactors(parameter);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
    CF2B_CountFactorTests, CF2B_CountFactorTest,
    ::testing::Values(std::make_pair(10, std::make_pair(1, 1)),
                      std::make_pair(2, std::make_pair(1, 0))));

class CF2B_FindShortestWeightedPathTest
    : public testing::TestWithParam<std::pair<GridType, int>>
{
};

TEST_P(CF2B_FindShortestWeightedPathTest, FindShortestPath)
{
    auto parameters = GetParam().first;
    auto expected = GetParam().second;
    DirectionType grid_of_parents(parameters.size(),
                                  std::vector<char>(parameters.size(), 'R'));
    auto result = FindShortestWeightedPath(parameters, grid_of_parents);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF2B_FindShortestWeightedPathTests, CF2B_FindShortestWeightedPathTest,
    ::testing::Values(std::make_pair(GridType{{1, 2},
                                              {5, 1}},
                                     4),
                      std::make_pair(GridType{{0, 0, 0},
                                              {0, 1, 0},
                                              {0, 0, 0}},
                                     0),
                      std::make_pair(GridType{{2, 1, 0},
                                              {1, 0, 2},
                                              {1, 0, 0}},
                                     3),
                      std::make_pair(GridType{{0, 1, 1},
                                              {1, 0, 0},
                                              {0, 1, 0}},
                                     1)));
// clang-format on

class CF2B_ReconstructPathTest
    : public testing::TestWithParam<std::pair<DirectionType, std::string>>
{
};

TEST_P(CF2B_ReconstructPathTest, ReconstructPath)
{
    const auto parameters = GetParam().first;
    const auto expected = GetParam().second;
    auto result = ReconstructPath(parameters);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF2B_ReconstructPathTests, CF2B_ReconstructPathTest,
    ::testing::Values(std::make_pair(DirectionType{{'R', 'R'}, 
                                                   {'D', 'D'}},
                                     "RD"),
                      std::make_pair(DirectionType{{'D', 'R', 'R'},
                                                   {'D', 'D', 'D'},
                                                   {'D', 'R', 'D'}},
                                     "RRDD")));
// clang-format on

class CF2B_PathThroughZeroTest
    : public testing::TestWithParam<
          std::pair<std::vector<std::size_t>, std::string>>
{
};

TEST_P(CF2B_PathThroughZeroTest, PathThroughZero)
{
    const auto parameters = GetParam().first;
    const auto expected = GetParam().second;
    auto result = PathThroughZero(parameters[0], parameters[1]);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF2B_PathThroughZeroTests, CF2B_PathThroughZeroTest,
    ::testing::Values(std::make_pair(std::vector<std::size_t>{3,1},
                                     "DRRD"),std::make_pair(std::vector<std::size_t>{4,2},
                                     "DDRRRD")));

// clang-format on
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
