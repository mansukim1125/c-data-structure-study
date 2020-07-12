#include <assert.h>
#include <stdio.h>

#include "week2.h"

// Run a binary search to search key at the row between [col_beg, col_end].
bool single_row_binary_search(int* matrix, int row, int col_beg, int col_end,
                              int key) {
  int width = col_end + 1;
  while (col_beg <= col_end) {
    // avoid overflow.
    int col_mid =
        col_beg + (col_end - col_beg) / 2;  // (col_beg + col_end) / 2;

    int value = matrix[row * width + col_mid];

    if (value == key) {
      return true;
    } else if (value < key) {
      col_beg = col_mid + 1;
    } else {
      col_end = col_mid - 1;
    }
  }

  return false;
}

bool binary_search(int* matrix, int height, int width, int key) {
  for (int row = 0; row < height; ++row) {
    if (single_row_binary_search(matrix, row, /*col_beg=*/0,
                                 /*col_end=*/width - 1, key))
      return true;
  }

  return false;
}

bool linear_search(int* matrix, int height, int width, int key) {
  int row = 0;
  int col = width - 1;

  while (row < height && 0 <= col) {
    while (0 <= col && key < matrix[row * width + col]) --col;
    if (matrix[row * width + col] == key) return true;

    while (row < height && matrix[row * width + col] < key) ++row;
    if (matrix[row * width + col] == key) return true;
  }

  return false;
}
