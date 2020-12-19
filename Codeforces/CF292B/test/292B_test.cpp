#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF292B_FindTopologyTest
    : public testing::TestWithParam<
          std::pair<std::pair<Graph, int>, std::string>>
{
};

TEST_P(CF292B_FindTopologyTest, FindTopology)
{
    auto graph = GetParam().first.first;
    auto edges = GetParam().first.second;
    auto nodes = graph.size();
    auto expected = GetParam().second;
    auto result = FindTopology(graph, nodes, edges);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF292B_FindTopologyTests, CF292B_FindTopologyTest,
    ::testing::Values(std::make_pair(std::make_pair(Graph{{1},{0,2},{1,3},{2,4},{3}},4), "bus topology"),
                      std::make_pair(std::make_pair(Graph{{1,2,3,4},{0},{0},{0},{0}},4), "star topology"),
                      std::make_pair(std::make_pair(Graph{{1,4},{0,2},{1,3},{2,4},{3,0}},5), "ring topology"),
                      std::make_pair(std::make_pair(Graph{{1,2,4},{0,2},{1,3,0},{2,4},{3,0}},5), "unknown topology"),
                      std::make_pair(std::make_pair(Graph{{1,2,3},{0,2},{1,0},{0}},4), "unknown topology")));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
