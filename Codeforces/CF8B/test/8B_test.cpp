#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "main.h"

class CF8B_CheckValidityOfPathTest
    : public testing::TestWithParam<std::pair<std::string, bool>> {};

TEST_P(CF8B_CheckValidityOfPathTest, CheckValidityOfPath) {
  auto directions = GetParam().first;
  auto expected = GetParam().second;
  auto result = CheckValidityOfPath(directions);
  EXPECT_EQ(result, expected);
}

// clang-format off
INSTANTIATE_TEST_CASE_P(
    CF8B_CheckValidityOfPathTests, CF8B_CheckValidityOfPathTest,
    ::testing::Values(std::make_pair("LLUUUR",true),
                      std::make_pair("RRUULLDD",false),
                      std::make_pair("RUL",false),
                      std::make_pair("L",true),
                      std::make_pair("DL",true),
                      std::make_pair("R",true)));
// clang-format on

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}