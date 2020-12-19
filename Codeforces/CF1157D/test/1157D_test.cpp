#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1157D_ConstructStrategyTest
    : public testing::TestWithParam<std::pair<
          std::pair<std::uint16_t, std::uint32_t>, std::vector<std::uint32_t>>>
{
};

TEST_P(CF1157D_ConstructStrategyTest, ConstructStrategy)
{

    auto parameters = GetParam().first;
    auto expected = GetParam().second;
    std::vector<std::uint32_t> problems(parameters.first);
    auto result = ConstructStrategy(problems, parameters.second);
    EXPECT_EQ(result, true);
    EXPECT_EQ(problems, expected);
}
// clang-format off
INSTANTIATE_TEST_CASE_P(CF1157D_ConstructStrategyTests, CF1157D_ConstructStrategyTest,
                        ::testing::Values(std::make_pair(std::make_pair(2,9), std::vector<std::uint32_t>{4,5}),
                                          std::make_pair(std::make_pair(2,10), std::vector<std::uint32_t>{4,6}),
                                          std::make_pair(std::make_pair(3,10), std::vector<std::uint32_t>{2,3,5}),
                                          std::make_pair(std::make_pair(3,11), std::vector<std::uint32_t>{2,3,6}),
                                          std::make_pair(std::make_pair(3,12), std::vector<std::uint32_t>{3,4,5}),
                                          std::make_pair(std::make_pair(3,12), std::vector<std::uint32_t>{3,4,5}),
                                          std::make_pair(std::make_pair(4,10), std::vector<std::uint32_t>{1,2,3,4}),
                                          std::make_pair(std::make_pair(4,15), std::vector<std::uint32_t>{2,3,4,6}),
                                          std::make_pair(std::make_pair(6,26), std::vector<std::uint32_t>{1,2,4,5,6,8})));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
