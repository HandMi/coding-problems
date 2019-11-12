#include "check_remainder.h"
#include "gtest/gtest.h"

class CF1256A_CheckRemainderTest
    : public testing::TestWithParam<std::tuple<std::array<int, 4>, bool>> {};

TEST_P(CF1256A_CheckRemainderTest, PredefinedTests) {
  auto parameters = std::get<0>(GetParam());
  auto expected = std::get<1>(GetParam());

  EXPECT_EQ(CheckRemainder(parameters[0], parameters[1], parameters[2],
                           parameters[3]),
            expected);
}

INSTANTIATE_TEST_CASE_P(
    CF1256A_CheckRemainderTests, CF1256A_CheckRemainderTest,
    ::testing::Values(std::make_tuple(std::array<int, 4>{1, 2, 3, 4}, true),
                      std::make_tuple(std::array<int, 4>{1, 2, 3, 6}, false),
                      std::make_tuple(std::array<int, 4>{5, 2, 6, 27}, false),
                      std::make_tuple(std::array<int, 4>{3, 3, 5, 18}, true)));

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
