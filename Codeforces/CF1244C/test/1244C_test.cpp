#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1244C_ReconstructStatsTest
    : public testing::TestWithParam<std::pair<
          std::tuple<long long, long long, int, int>, std::array<long long, 3>>>
{
};

TEST_P(CF1244C_ReconstructStatsTest, ReconstructStats)
{
    auto n = std::get<0>(GetParam().first);
    auto p = std::get<1>(GetParam().first);
    auto w = std::get<2>(GetParam().first);
    auto d = std::get<3>(GetParam().first);
    auto expected = GetParam().second;
    auto result = ReconstructStats(n, p, w, d);
    EXPECT_EQ(result, expected);
}
// clang-format off
INSTANTIATE_TEST_CASE_P(CF1244C_ReconstructStatsTests, CF1244C_ReconstructStatsTest,
                        ::testing::Values(std::make_pair(std::make_tuple(30,60,3,1), std::array<long long,3>{20,0,10}),
                                          std::make_pair(std::make_tuple(10,51,5,4), std::array<long long,3>{7,4,-1}),
                                          std::make_pair(std::make_tuple(20,0,15,5), std::array<long long,3>{0,0,20}),
                                          std::make_pair(std::make_tuple(10,2,5,3), std::array<long long,3>{-2,4,8}),
                                          std::make_pair(std::make_tuple(1000000000000,1000000000000,6,3), std::array<long long,3>{166666666662,-1,833333333339}),
                                          std::make_pair(std::make_tuple(1000000000000,99999999999999999,100000,99999), std::array<long long,3>{999999999999,1,0})));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
