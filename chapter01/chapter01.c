#include "chapter01.h"

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
  if (a < b) return b;
  return a;
}

int max4_q1(int a, int b, int c, int d) { return max(max(max(a, b), c), d); }

void swap(int xs[3], int i, int j) {
  int temp = xs[i];
  xs[i] = xs[j];
  xs[j] = temp;
}

int partition(int xs[3], int left, int right) {
  int w_idx = left;
  int pivot = xs[right];
  for (int i = left; i <= right - 1; ++i) {
    if (xs[i] < pivot) {
      swap(xs, w_idx++, i);
    }
  }
  swap(xs, w_idx, right);
  return w_idx;
}

void sort(int xs[3], int left, int right) {
  if (left < right) {
    int pivot = partition(xs, left, right);
    sort(xs, left, pivot - 1);
    sort(xs, pivot + 1, right);
  }
}

int med3_q2(int a, int b, int c) {
  int arr[3];
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;

  sort(arr, 0, 2);

  return arr[1];
}

int min(int a, int b) { return a < b ? a : b; }

// Q2
int min3_q3(int a, int b, int c) { return min(min(a, b), c); }
// Q3
int min4_q5(int a, int b, int c, int d) { return min(min3_q3(a, b, c), d); }

// Q6
void run_q6() {
  puts("sum between 1 and n");
  printf("Input n: ");
  int n;
  scanf("%d", &n);

  int sum = 0;
  int i = 1;
  while (i <= n) {
    sum += i;
    i++;
    printf("i = %d\n", i);
  }
  printf("sum between 1 and %d = %d\n",n, sum);
}

int sum_until_q7(int n) {
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += i;
  return sum;
}

int sum_until_q8(int n) { return n * (n + 1) / 2; }
int sumof_q9(int a, int b) {
  if (a > b) return sumof_q9(b, a);
  int sum = 0;
  for (int i = a; i <= b; ++i) sum += i;
  return sum;
}

int get_number_of_digits_q11(int n) {
  int size = 0;
  while (n > 0) {
    n /= 10;
    size++;
  }
  return size;
}

char* to_string(int value, char* buffer) {
  size_t i = 0;
  while (value) {
    int digit = value % 10;
    buffer[i++] = digit + '0';
    value /= 10;
  }
  buffer[i] = '\0';
  int n = strlen(buffer);
  for (i = 0; i < strlen(buffer) / 2; ++i) {
    char temp = buffer[i];
    buffer[i] = buffer[n - 1 - i];
    buffer[n - 1 - i] = temp;
  }
  return buffer;
}

char** print_multiplication_table_q12() {
  char** result = calloc(11, sizeof(char*));
  for (size_t i = 0; i < 11; ++i) {
    result[i] = calloc(33, sizeof(char));
  }
  result[0] = "   | 1  2  3  4  5  6  7  8  9 \n";
  result[1] = "---+---------------------------\n";

  char buffer[32];

  for (size_t row = 2; row < 11; ++row) {
    int value = row - 1;
    char* header = to_string(value, buffer);
    strcpy(result[row], " ");
    strcat(result[row], header);
    strcat(result[row], " |");

    for (int i = 1; i <= 9; ++i) {
      strcat(result[row], " ");
      char* val = to_string(value * i, buffer);
      strcat(result[row], val);

      if (value * i < 10) strcat(result[row], " ");
    }
    strcat(result[row], "\n");
  }

  return result;
}

char** spira_q17(int n) {
  int width = 2 * (n - 1) + 2;
  char** result = calloc(n, sizeof(char*));
  for (size_t i = 0; i < n; ++i) {
    result[i] = calloc(width, sizeof(char));
    memset(result[i], ' ', width);
    result[i][width - 1] = '\0';
  }

  size_t len = width - 1;
  size_t mid = len / 2;

  for (size_t row = 0; row < n; ++row) {
    for (size_t i = mid; i < len; ++i) {
      if (i - mid <= row) {
        result[row][i] = '*';
        result[row][len - 1 - i] = '*';
      }
    }
  }

  return result;
}
