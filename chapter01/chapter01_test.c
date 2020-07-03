#include <stdlib.h>

#include "chapter01.h"
#include "unity/unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_max4_q1(void) { TEST_ASSERT_EQUAL_INT(max4_q1(1, 2, 3, 4), 4); }

void test_med3_q2(void) {
  TEST_ASSERT_EQUAL_INT(med3_q2(1, 2, 3), 2);
  TEST_ASSERT_EQUAL_INT(med3_q2(1, 2, 2), 2);
  TEST_ASSERT_EQUAL_INT(med3_q2(1, 1, 1), 1);
  TEST_ASSERT_EQUAL_INT(med3_q2(3, 2, 1), 2);
}

void test_min3_q3(void) { TEST_ASSERT_EQUAL_INT(min3_q3(1, 2, 3), 1); }

void test_min4_q5(void) {
  TEST_ASSERT_EQUAL_INT(min4_q5(1, 2, 3, 4), 1);
  TEST_ASSERT_EQUAL_INT(min4_q5(1, 2, 3, -10), -10);
}

void test_run_q6(void) { run_q6(); }

void test_sum_until_q7(void) {
  TEST_ASSERT_EQUAL_INT(sum_until_q7(7), 28);
  TEST_ASSERT_EQUAL_INT(sum_until_q7(8), 36);
}

void test_sum_until_q8(void) {
  TEST_ASSERT_EQUAL_INT(sum_until_q8(7), 28);
  TEST_ASSERT_EQUAL_INT(sum_until_q8(8), 36);
}

void test_sumof_q9(void) {
  TEST_ASSERT_EQUAL_INT(6, sumof_q9(1, 3));
  TEST_ASSERT_EQUAL_INT(3, sumof_q9(3, 3));
  TEST_ASSERT_EQUAL_INT(6, sumof_q9(3, 1));
}

void test_get_number_of_digits_q11(void) {
  TEST_ASSERT_EQUAL_INT(3, get_number_of_digits_q11(135));
  TEST_ASSERT_EQUAL_INT(4, get_number_of_digits_q11(1314));
}

void test_print_multiplication_table_q12(void) {
  char** result = print_multiplication_table_q12();
  const char* expected[] = {
    "   | 1  2  3  4  5  6  7  8  9 \n",
    "---+---------------------------\n",
    " 1 | 1  2  3  4  5  6  7  8  9 \n",
    " 2 | 2  4  6  8  10 12 14 16 18\n",
    " 3 | 3  6  9  12 15 18 21 24 27\n",
    " 4 | 4  8  12 16 20 24 28 32 36\n",
    " 5 | 5  10 15 20 25 30 35 40 45\n",
    " 6 | 6  12 18 24 30 36 42 48 54\n",
    " 7 | 7  14 21 28 35 42 49 56 63\n",
    " 8 | 8  16 24 32 40 48 56 64 72\n",
    " 9 | 9  18 27 36 45 54 63 72 81\n",
  };
  TEST_ASSERT_EQUAL_STRING_ARRAY(expected, result, 11);

  free(result);
}

void test_print_spira_q17(void) {
  const char* expected[] = {
    "   *   ",
    "  ***  ",
    " ***** ",
    "*******",
  };
  char** actual = spira_q17(4);
  TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, 4);

  for (int i = 0; i < 4; ++i) {
    free(actual[i]);
  }
  free(actual);

}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_max4_q1);
  RUN_TEST(test_med3_q2);
  RUN_TEST(test_min3_q3);
  RUN_TEST(test_min4_q5);
  RUN_TEST(test_run_q6);
  RUN_TEST(test_sum_until_q7);
  RUN_TEST(test_sum_until_q8);
  RUN_TEST(test_sumof_q9);
  RUN_TEST(test_get_number_of_digits_q11);
  RUN_TEST(test_print_multiplication_table_q12);
  RUN_TEST(test_print_spira_q17);
  return UNITY_END();
}
