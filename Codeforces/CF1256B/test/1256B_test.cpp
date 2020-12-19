#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1256B_MinimalPermutationTest
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<int>>>
{
};

TEST_P(CF1256B_MinimalPermutationTest, PredefinedTests)
{
    auto parameters = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());
    MinimalPermutation(parameters);
    EXPECT_EQ(parameters.size(), expected.size());
    EXPECT_THAT(parameters, ::testing::ContainerEq(expected));
}

INSTANTIATE_TEST_CASE_P(
    CF1256B_MinimalPermutationTests, CF1256B_MinimalPermutationTest,
    ::testing::Values(std::make_tuple(std::vector<int>{5, 4, 1, 3, 2},
                                      std::vector<int>{1, 5, 2, 4, 3}),
                      std::make_tuple(std::vector<int>{1}, std::vector<int>{1}),
                      std::make_tuple(std::vector<int>{1, 2, 4, 3},
                                      std::vector<int>{1, 2, 3, 4}),
                      std::make_tuple(std::vector<int>{4, 3, 2, 1},
                                      std::vector<int>{1, 4, 3, 2})));

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
