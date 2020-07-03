#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

// [0.1, 0.2, ..., 1.0]
char** print_vision_table_of_people_q12(double people[], int n_people) {
  const int N = 10;
  const int max_width = 255;
  char** actual = calloc(N, sizeof(char*));

  char buffer[255];
  for (size_t i = 0; i < N; ++i) {
    actual[i] = calloc(max_width, sizeof(char));

    sprintf(buffer, "%0.1f~:", (i + 1) / 10.0);
    strcpy(actual[i], buffer);
  }

  for (size_t i = 0; i < n_people; ++i) {
    int sight = (int)(people[i] * 10.0) - 1;
    assert(0 <= sight);
    assert(sight < N);
    strcat(actual[sight], "*");
  }

  return actual;
}


typedef struct {
  int y;
  int m;
  int d;
} Date;

Date DateOf(int y, int m, int d) {
  Date date = {
      .y = y,
      .m = m,
      .d = d,
  };
  return date;
}

bool date_equal(Date d1, Date d2) {
  return d1.y == d2.y && d1.m == d2.m && d1.d == d2.d;
}

Date After(Date x, int n) {
  struct tm tm_date = {
      .tm_year = x.y,
      .tm_mon = x.m - 1,
      .tm_mday = x.d,
  };

  tm_date.tm_isdst = false;
  mktime(&tm_date);

  tm_date.tm_mday += n;
  mktime(&tm_date);

  return DateOf(tm_date.tm_year, tm_date.tm_mon + 1, tm_date.tm_mday);
}

Date Before(Date x, int n) {
  return After(x, -n);
}
