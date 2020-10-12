#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "main.h"

class CF1256C_CrossRiverTest
    : public testing::TestWithParam<
          std::tuple<std::pair<int, std::vector<int>>,
                     std::pair<std::vector<int>, bool>>> {};

TEST_P(CF1256C_CrossRiverTest, CrossRiverTest) {
  auto parameters = std::get<0>(GetParam());
  auto expected = std::get<1>(GetParam());
  std::vector<int> river(expected.first.size());
  auto result = CrossRiver(river, parameters.first, parameters.second);
  EXPECT_EQ(result, expected.second);
  EXPECT_EQ(river, expected.first);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF1256C_CrossRiverTest, CF1256C_CrossRiverTest,
    ::testing::Values(std::make_tuple(std::make_pair(2,std::vector<int>{2, 2}),
                                      std::make_pair(std::vector<int>{0, 1, 1, 2, 2},true)),
                      std::make_tuple(std::make_pair(2,std::vector<int>{2, 2}),
                                      std::make_pair(std::vector<int>{0, 1, 1, 0, 2, 2},true)),
                      std::make_tuple(std::make_pair(2,std::vector<int>{3}),
                                      std::make_pair(std::vector<int>{0, 1, 1, 1, 0},true)),
                      std::make_tuple(std::make_pair(2,std::vector<int>{2}),
                                      std::make_pair(std::vector<int>{0, 1, 1, 0, 0},false)),
                      std::make_tuple(std::make_pair(3,std::vector<int>{3}),
                                      std::make_pair(std::vector<int>{0, 0, 1, 1, 1},true)),
                      std::make_tuple(std::make_pair(3,std::vector<int>{1,2}),
                                      std::make_pair(std::vector<int>{0, 0, 1, 0, 0, 2, 2, 0},true)),
                      std::make_tuple(std::make_pair(3,std::vector<int>{1,2}),
                                      std::make_pair(std::vector<int>{0, 0, 1, 0, 0, 2, 2, 0, 0, 0},false))));
// clang-format on

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
