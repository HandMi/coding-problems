#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP008_LargestProductTest
    : public testing::TestWithParam<std::pair<std::string, long>>
{
};

TEST_P(PEP008_LargestProductTest, LargestProductTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    auto result = LargestProduct(n, 5);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP008_LargestProductTests, PEP008_LargestProductTest,
    ::testing::Values(std::make_pair("3675356291",3150),
                      std::make_pair("2709360626",0)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
