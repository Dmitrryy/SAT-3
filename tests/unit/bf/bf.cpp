import BfRtSAT;
#include "gtest/gtest.h"

TEST(bruteForce, test0) {
  std::vector<std::tuple<int, int, int>> test = {{1, 2, -3}, {2, 3, -1}};
  std::vector<int> vars;

  EXPECT_TRUE(solve(test, vars));
  EXPECT_TRUE(isSolution(vars, test));

  EXPECT_TRUE(isSolution({1, 0, 1}, test));
  EXPECT_TRUE(isSolution({1, 1, 1}, test));

  EXPECT_FALSE(isSolution({1, 0, 0}, test));
}

TEST(bruteForce, test1) {
  std::vector<std::tuple<int, int, int>> test = {
      {1, 2, -3}, {-1, -2, 3}, {-1, 2, -3}, {-1, -2, -3},
      {1, 2, 3},  {1, -2, 3},  {1, -2, -3}, {-1, 2, 3}};
  std::vector<int> vars;

  EXPECT_FALSE(solve(test, vars));
  EXPECT_FALSE(isSolution(vars, test));

  EXPECT_FALSE(isSolution({1, 0, 1}, test));
  EXPECT_FALSE(isSolution({1, 1, 1}, test));

  EXPECT_FALSE(isSolution({1, 0, 0}, test));
}
