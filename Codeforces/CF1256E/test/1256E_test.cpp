#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ParticipantList = std::vector<std::vector<std::uint32_t>>;

class CF1256E_TeamComplexityTest
    : public testing::TestWithParam<
          std::pair<std::vector<StudentType>, std::pair<long long, int>>>
{
};

TEST_P(CF1256E_TeamComplexityTest, CF1256E_TeamComplexity)
{
    auto parameters = GetParam().first;
    auto expected = GetParam().second;
    std::vector<int> id_to_team_map;
    auto result = TeamComplexity(parameters, id_to_team_map);

    EXPECT_EQ(result.first, expected.first);
    EXPECT_EQ(result.second, expected.second);
};
// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF1256E_TeamComplexityTests, CF1256E_TeamComplexityTest,
    ::testing::Values(
        std::make_pair(std::vector<StudentType>{{1,0},{1,1},{3,2},{4,3},{2,4}},std::make_pair(3,1)),
        std::make_pair(std::vector<StudentType>{{1,0},{5,1},{12,2},{13,3},{2,4},{15,5}},std::make_pair(7,2)),
        std::make_pair(std::vector<StudentType>{{1,0},{2,1},{5,2},{129,3},{185,4},{581,5},{1041,6},{1909,7},{1580,8},{8150,9}},std::make_pair(7486,3))));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
