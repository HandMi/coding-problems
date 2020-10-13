#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "main.h"


class CF618D_CalculateDegreeTest
    : public testing::TestWithParam<std::pair<Tree, int>> {};

TEST_P(CF618D_CalculateDegreeTest, CalculateDegree) {
  auto tree = GetParam().first;
  auto expected = GetParam().second;
  auto result = GetDegreeOfTree(tree);
  EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF618D_CalculateDegreeTests, CF618D_CalculateDegreeTest,
    ::testing::Values(std::make_pair(Tree{{1},{0}}, 1),
                      std::make_pair(Tree{{2},{2},{0, 1, 3}, {2, 4, 5}, {3}, {3}}, 3),
                      std::make_pair(Tree{{2},{2},{0, 1, 3, 4, 5}, {2}, {2}, {2}}, 5)));
// clang-format on

class CF618D_CountUseableEdgesTest
    : public testing::TestWithParam<std::pair<Tree, int>> {};

TEST_P(CF618D_CountUseableEdgesTest, CountUseableEdges) {
  auto tree = GetParam().first;
  auto expected = GetParam().second;
  auto result = CountUseableEdges(tree);
  EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF618D_CountUseableEdgesTests, CF618D_CountUseableEdgesTest,
    ::testing::Values(std::make_pair(Tree{{1},{0}}, 1),
                      std::make_pair(Tree{{2},{2},{0, 1, 3}, {2, 4, 5}, {3}, {3}}, 4),
                      std::make_pair(Tree{{2},{2},{0, 1, 3, 4, 5}, {2}, {2}, {2}}, 2),
                      std::make_pair(Tree{{1, 2},{0},{0, 3, 4}, {2}, {2}}, 3)));
// clang-format on

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}