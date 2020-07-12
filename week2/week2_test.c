#include "unity/unity.h"
#include "week2.h"

void setUp() {}
void tearDown() {}

void test_binary_search_2d_5x5(void) {
  // clang-format off
  int buffer[][5] = {{1,  4,  7,  11, 15},
                     {2,  5,  8,  12, 19},
                     {3,  6,  9,  16, 22},
                     {10, 13, 14, 17, 24},
                     {18, 21, 23, 26, 30}};
  // clang-format on

  TEST_ASSERT_TRUE(
      binary_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/5));
  TEST_ASSERT_TRUE(
      binary_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/10));
  TEST_ASSERT_FALSE(
      binary_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/20));
}


void test_binary_search_2d_2x5(void) {
  // clang-format off
  int buffer[][5] = {{1,  3,  4,  5,  15},
                     {2,  7,  8,  12, 19}};
  // clang-format on

  TEST_ASSERT_TRUE(
      binary_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/4));
  TEST_ASSERT_TRUE(
      binary_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/7));
  TEST_ASSERT_FALSE(
      binary_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/6));
}

void test_linear_search_2d_5x5(void) {
  // clang-format off
  int buffer[][5] = {{1,  4,  7,  11, 15},
                     {2,  5,  8,  12, 19},
                     {3,  6,  9,  16, 22},
                     {10, 13, 14, 17, 24},
                     {18, 21, 23, 26, 30}};
  // clang-format on

  TEST_ASSERT_TRUE(
      linear_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/5));
  TEST_ASSERT_TRUE(
      linear_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/10));
  TEST_ASSERT_FALSE(
      linear_search((int*)buffer, /*height*/ 5, /*width=*/5, /*key=*/20));
}


void test_linear_search_2d_2x5(void) {
  // clang-format off
  int buffer[][5] = {{1,  3,  4,  5,  15},
                     {2,  7,  8,  12, 19}};
  // clang-format on

  TEST_ASSERT_TRUE(
      linear_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/4));
  TEST_ASSERT_TRUE(
      linear_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/7));
  TEST_ASSERT_FALSE(
      linear_search((int*)buffer, /*height*/ 2, /*width=*/5, /*key=*/6));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_binary_search_2d_5x5);
  RUN_TEST(test_binary_search_2d_2x5);

  RUN_TEST(test_linear_search_2d_5x5);
  RUN_TEST(test_linear_search_2d_2x5);

  return UNITY_END();
}
