#include <unity/unity.h>

#include "week4.h"

void setUp() {}
void tearDown() {}

void test_solve_simple() {
  TEST_ASSERT_EQUAL(4, solve(4));
  TEST_ASSERT_EQUAL(4, solve(6));
}

void test_circular_queue_basic_functionalities() {
  Queue q = new_queue();
  TEST_ASSERT_TRUE(is_empty(&q));

  push(&q, 1);
  push(&q, 2);
  push(&q, 3);

  TEST_ASSERT_EQUAL(3, size(&q));

  TEST_ASSERT_EQUAL(1, peek(&q));

  TEST_ASSERT_EQUAL(1, pop(&q));
  TEST_ASSERT_EQUAL(2, pop(&q));
  TEST_ASSERT_EQUAL(3, pop(&q));

  TEST_ASSERT_TRUE(is_empty(&q));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_solve_simple);
  RUN_TEST(test_circular_queue_basic_functionalities);

  return UNITY_END();
}
