#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

char buffer[2187][2187];

void Solve(int n, int row, int col) {
  if (n == 1) {
    buffer[row][col] = '*';
    return;
  }

  int next = n / 3;

  for (size_t d_row = 0; d_row < 3; ++d_row) {
    for (size_t d_col = 0; d_col < 3; ++d_col) {
      if (d_row == 1 && d_col == 1) continue;
      int next_row = row + d_row * next;
      int next_col = col + d_col * next;
      Solve(next, next_row, next_col);
    }
  }
}

void Print(int n) {
  for (size_t row = 0; row < n; ++row) {
    for (size_t col = 0; col < n; ++col) {
      printf("%c", buffer[row][col]);
    }
    putchar('\n');
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  memset(buffer, ' ', sizeof(buffer));

  Solve(n, 0, 0);
  Print(n);


  return 0;
}