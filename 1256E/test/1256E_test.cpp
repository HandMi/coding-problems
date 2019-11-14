#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "main.h"

using ParticipantList = std::vector<std::vector<std::uint32_t>>;

class CF1256E_LongestIncreasingSubsequenceTest
    : public testing::TestWithParam<
          std::tuple<std::vector<std::uint32_t>, std::uint32_t>> {};

TEST_P(CF1256E_LongestIncreasingSubsequenceTest,
       CF1256E_LongestIncreasingSubsequence) {
  auto parameters = std::get<0>(GetParam());
  auto expected = std::get<1>(GetParam());
  auto result = LongestIncreasingSubsequence(parameters);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
    CF1256E_LongestIncreasingSubsequenceTests,
    CF1256E_LongestIncreasingSubsequenceTest,
    ::testing::Values(
        std::make_tuple(std::vector<std::uint32_t>{5, 4, 1, 3, 2}, 2),
        std::make_tuple(std::vector<std::uint32_t>{1, 2, 3, 5, 4}, 4),
        std::make_tuple(std::vector<std::uint32_t>{1, 2, 3, 4, 5}, 5),
        std::make_tuple(std::vector<std::uint32_t>{5, 4, 3, 2, 1}, 1)));

class CF1256E_MinimumMovesTest
    : public testing::TestWithParam<
          std::tuple<ParticipantList, std::uint32_t>> {};

TEST_P(CF1256E_MinimumMovesTest, CF1256E_MinimumMoves) {
  auto parameters = std::get<0>(GetParam());
  auto expected = std::get<1>(GetParam());
  auto result = MinimumMoves(parameters);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(
    CF1256E_MinimumMovesTests, CF1256E_MinimumMovesTest,
    ::testing::Values(
        std::make_tuple(ParticipantList{std::vector<std::uint32_t>{3, 1},
                                        std::vector<std::uint32_t>{4},
                                        std::vector<std::uint32_t>{2, 5}},
                        1),
        std::make_tuple(ParticipantList{std::vector<std::uint32_t>{5, 6},
                                        std::vector<std::uint32_t>{4},
                                        std::vector<std::uint32_t>{1, 2, 3}},
                        3),
        std::make_tuple(ParticipantList{std::vector<std::uint32_t>{3, 2, 1},
                                        std::vector<std::uint32_t>{5, 4},
                                        std::vector<std::uint32_t>{6}},
                        0),
        std::make_tuple(ParticipantList{std::vector<std::uint32_t>{6},
                                        std::vector<std::uint32_t>{5, 1, 2, 4,
                                                                   7},
                                        std::vector<std::uint32_t>{3}},
                        2)));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
