#include "week3/week3.h"

#include <unity/unity.h>

void setUp() {}
void tearDown() {}

void test_solution() {
  int input[][5] = {
      // clang-format off
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 3},
      {0, 2, 5, 0, 1},
      {4, 2, 4, 4, 2},
      {3, 5, 1, 3, 1},
      // clang-format on
  };
  int moves[8] = {1, 5, 3, 5, 1, 2, 1, 4};

  TEST_ASSERT_EQUAL_INT(4, solution(
                               /*n_input=*/5, input,
                               /*n_moves=*/8, moves));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_solution);
  return UNITY_END();
}