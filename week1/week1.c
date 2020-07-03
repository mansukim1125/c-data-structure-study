#include "week1.h"

int** spiral_matrix(size_t size) {
  if (size == 0) return NULL;
  // Allocate memory.
  int** result = calloc(size, sizeof(int*));
  for (size_t i = 0; i < size; ++i) {
    result[i] = calloc(size, sizeof(int));
  }

  size_t row_beg = 0;
  size_t row_end = size - 1;

  size_t col_beg = 0;
  size_t col_end = size - 1;

  int value = 1;

  // The same number means it is in the same loop.
  // 1 1 1 1 1
  // 4 5 5 5 2
  // 4 8 9 6 2
  // 4 8 7 6 2
  // 4 3 3 3 2
  while (row_beg <= row_end && col_beg <= col_end) {
    for (int c = col_beg; c <= col_end; ++c) {
      result[row_beg][c] = value++;
    }

    for (int r = row_beg + 1; r <= row_end; ++r) {
      result[r][col_end] = value++;
    }

    for (int c = col_end - 1; col_beg < c; --c ) {
      result[row_end][c] = value++;
    }

    for (int r = row_end; row_beg < r; --r) {
      result[r][col_beg] = value++;
    }

    row_beg++;
    row_end--;

    col_beg++;
    col_end--;
  }

  return result;
}
