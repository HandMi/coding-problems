#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF131D_GetDistancesFromRingroadTest
    : public testing::TestWithParam<std::pair<Graph, std::vector<int>>>
{
};

TEST_P(CF131D_GetDistancesFromRingroadTest, GetDistancesFromRingroad)
{
    auto graph = GetParam().first;
    Subway subway(graph);
    auto expected = GetParam().second;
    auto result = subway.GetDistancesFromRingroad();
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF131D_GetDistancesFromRingroadTests, CF131D_GetDistancesFromRingroadTest,
    ::testing::Values(std::make_pair(Graph{{1,2},{3,0},{3,0}, {2,1}}, std::vector<int>{0,0,0,0}),
                      std::make_pair(Graph{{1,2},{0,2},{3,1,0,4}, {2,5},{2},{3}}, std::vector<int>{0,0,0,1,1,2})));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
