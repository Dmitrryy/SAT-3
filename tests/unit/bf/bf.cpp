import BfRtSAT;
#include "gtest/gtest.h"

TEST(bruteForce, test0) {
  std::array<std::tuple<int, int, int>, 2> test = {{{1, 2, -3}, {2, 3, -1}}};

  auto res = solve<3>(test);
  EXPECT_TRUE(res.has_value());
  EXPECT_TRUE(isSolution(res.value(), test));

  EXPECT_TRUE(isSolution(std::array<int, 3>{1, 0, 1}, test));
  EXPECT_TRUE(isSolution(std::array<int, 3>{1, 1, 1}, test));

  EXPECT_FALSE(isSolution(std::array<int, 3>{1, 0, 0}, test));
}

TEST(bruteForce, test1) {
  std::array<std::tuple<int, int, int>, 8> test = {{
      {1, 2, -3}, {-1, -2, 3}, {-1, 2, -3}, {-1, -2, -3},
      {1, 2, 3},  {1, -2, 3},  {1, -2, -3}, {-1, 2, 3}}};

  EXPECT_FALSE(solve<3>(test).has_value());

  EXPECT_FALSE(isSolution(std::array<int, 3>{1, 0, 1}, test));
  EXPECT_FALSE(isSolution(std::array<int, 3>{1, 1, 1}, test));

  EXPECT_FALSE(isSolution(std::array<int, 3>{1, 0, 0}, test));
}

TEST(bruteForce, compile0) {
  constexpr std::array<std::tuple<int, int, int>, 2> test = {{{1, 2, -3}, {2, 3, -1}}};

  constexpr auto solv_res = solve_compile<3>(test);
  constexpr auto res2 = isSolution(solv_res.value(), test);
  EXPECT_TRUE(res2);

  constexpr auto res3 = isSolution(std::array<int, 3>{1, 0, 1}, test);
  EXPECT_TRUE(res3);
  constexpr auto res4 = isSolution(std::array<int, 3>{1, 1, 1}, test);
  EXPECT_TRUE(res4);

  constexpr auto res5 = isSolution(std::array<int, 3>{1, 0, 0}, test);
  EXPECT_FALSE(res5);
}

TEST(bruteForce, compile1) {
  constexpr std::array<std::tuple<int, int, int>, 8> test = {{{1, 2, -3},
                                                              {-1, -2, 3},
                                                              {-1, 2, -3},
                                                              {-1, -2, -3},
                                                              {1, 2, 3},
                                                              {1, -2, 3},
                                                              {1, -2, -3},
                                                              {-1, 2, 3}}};
  constexpr auto solv_res = solve_compile<3>(test);
  EXPECT_FALSE(solv_res.has_value());

  constexpr auto res2 = isSolution(std::array<int, 3>{1, 0, 1}, test);
  EXPECT_FALSE(res2);
  constexpr auto res3 = isSolution(std::array<int, 3>{1, 1, 1}, test);
  EXPECT_FALSE(res3);

  constexpr auto res4 = isSolution(std::array<int, 3>{1, 0, 0}, test);
  EXPECT_FALSE(res4);
}
