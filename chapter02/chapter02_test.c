#include <unity/unity.h>

#include "chapter02.h"

void setUp() {}
void tearDown() {}

void test_q12() {
  double input[] = {0.1, 0.2, 0.2, 0.2, 0.3};
  const char* expected[] = {
      "0.1~:*", "0.2~:***", "0.3~:*", "0.4~:", "0.5~:",
      "0.6~:",  "0.7~:",    "0.8~:",  "0.9~:", "1.0~:",
  };

  int N_VISION_RESULT = sizeof(expected) / sizeof(expected[0]);

  char** actual =
      print_vision_table_of_people_q12(input, sizeof(input) / sizeof(input[0]));
  TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, N_VISION_RESULT);

  for (size_t i = 0; i < N_VISION_RESULT; ++i) free(actual[i]);
  free(actual);
}

void test_date_equal() {
  Date d1 = {.y = 2010, .m = 1, .d = 3};
  Date d2 = {.y = 2010, .m = 1, .d = 3};

  TEST_ASSERT_TRUE(date_equal(d1, d2));
}

void test_date_after() {
  Date d1 = {.y = 2010, .m = 1, .d = 3};

  Date expected = {.y = 2010, .m = 1, .d = 4};

  TEST_ASSERT_TRUE(date_equal(expected, After(d1, 1)));
}

void test_date_after_month_change() {
  Date d1 = {.y = 2020, .m = 6, .d = 30};

  Date expected = {.y = 2020, .m = 7, .d = 1};

  TEST_ASSERT_TRUE(date_equal(expected, After(d1, 1)));
}

void test_date_before_month_change() {
  Date d1 = {.y = 2020, .m = 7, .d = 1};

  Date expected = {.y = 2020, .m = 6, .d = 30};

  TEST_ASSERT_TRUE(date_equal(expected, Before(d1, 1)));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_q12);
  RUN_TEST(test_date_equal);
  RUN_TEST(test_date_after);
  RUN_TEST(test_date_after_month_change);
  RUN_TEST(test_date_before_month_change);

  return UNITY_END();
}
