#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CF1257D_FilterHeroesTest
    : public testing::TestWithParam<
          std::pair<std::vector<HeroType>, std::vector<HeroType>>>
{
};

TEST_P(CF1257D_FilterHeroesTest, FilterHeroes)
{
    auto parameter = GetParam().first;
    const auto expected = GetParam().second;
    FilterHeroes(parameter);
    EXPECT_EQ(parameter, expected);
}
// clang-format off
INSTANTIATE_TEST_CASE_P(CF1257D_FilterHeroesTests, CF1257D_FilterHeroesTest,
                        ::testing::Values(std::make_pair(
                            std::vector<HeroType>{
                              std::make_pair(5, 2), 
                              std::make_pair(4, 1),
                              std::make_pair(3, 1),
                              std::make_pair(2, 3)
                            },
                            std::vector<HeroType>{
                              std::make_pair(5, 2), 
                              std::make_pair(2, 3)
                            }),
                            std::make_pair(
                            std::vector<HeroType>{
                              std::make_pair(7, 5), 
                              std::make_pair(6, 5),
                              std::make_pair(5, 2),
                              std::make_pair(4, 3),
                              std::make_pair(3, 7),
                              std::make_pair(2, 9)
                            },
                            std::vector<HeroType>{
                              std::make_pair(7, 5), 
                              std::make_pair(3, 7),
                              std::make_pair(2, 9)
                            }),
                            std::make_pair(
                            std::vector<HeroType>{
                              std::make_pair(7, 6), 
                              std::make_pair(8, 6),
                              std::make_pair(9, 6),
                              std::make_pair(8, 9),
                              std::make_pair(10, 6),
                              std::make_pair(10, 6)
                            },
                            std::vector<HeroType>{
                              std::make_pair(10, 6), 
                              std::make_pair(8, 9)
                            })));
// clang-format on

class CF1257D_CalculateDaysInDungeonTest
    : public testing::TestWithParam<
          std::pair<std::pair<std::vector<HeroType>, std::vector<int>>, int>>
{
};

TEST_P(CF1257D_CalculateDaysInDungeonTest, CalculateDaysInDungeon)
{
    auto parameter = GetParam().first;
    const auto expected = GetParam().second;
    auto result = CalculateDaysInDungeon(parameter.first, parameter.second);
    EXPECT_EQ(result, expected);
}
// clang-format off
INSTANTIATE_TEST_CASE_P(CF1257D_CalculateDaysInDungeonTests, CF1257D_CalculateDaysInDungeonTest,
                        ::testing::Values(std::make_pair(
                            std::make_pair(
                              std::vector<HeroType>{ 
                              std::make_pair(2, 3),
                              std::make_pair(1, 100)
                            },
                              std::vector<int>{2, 3, 11, 14, 1, 8}),
                            5),
                            std::make_pair(
                            std::make_pair(
                            std::vector<HeroType>{
                              std::make_pair(5, 30), 
                              std::make_pair(1, 90)
                            },
                              std::vector<int>{2, 3, 100, 14, 1, 8}
                            ),
                            -1
                            ),
                            std::make_pair(
                            std::make_pair(
                            std::vector<HeroType>{
                              std::make_pair(5, 30), 
                              std::make_pair(1, 90)
                            },
                              std::vector<int>{2, 3, 80, 14, 1, 8}
                            ),
                            3
                            )));
// clang-format on
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}