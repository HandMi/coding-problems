#include "main.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class PEP017_WordsToNumberTest
    : public testing::TestWithParam<std::pair<std::string, std::uint64_t>>
{
};

TEST_P(PEP017_WordsToNumberTest, WordsToNumberTest)
{
    auto n = GetParam().first;
    auto expected = GetParam().second;
    auto result = WordsToNumber(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP017_WordsToNumberTests, PEP017_WordsToNumberTest,
    ::testing::Values(std::make_pair("Ten",10),
                      std::make_pair("One Hundred Four Billion Three Hundred Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve", 104382426112)));
// clang-format on

class PEP017_NumberToWordsTest
    : public testing::TestWithParam<std::pair<std::string, std::uint64_t>>
{
};

TEST_P(PEP017_NumberToWordsTest, NumberToWordsTest)
{
    auto n = GetParam().second;
    auto expected = GetParam().first;
    auto result = NumberToWords(n);
    EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    PEP017_NumberToWordsTests, PEP017_NumberToWordsTest,
    ::testing::Values(std::make_pair("Ten",10),
                      std::make_pair("One Hundred Four Billion Three Hundred Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve", 104382426112),
                      std::make_pair("One Hundred Four", 104),
                      std::make_pair("One Hundred", 100),
                      std::make_pair("One Thousand", 1000),
                      std::make_pair("One Billion Ten Million", 1010000000),
                      std::make_pair("One Billion Ten Thousand", 1000010000)));
// clang-format on

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
