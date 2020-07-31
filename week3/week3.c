#include "week3/week3.h"

#include <stdlib.h>

int stack[150];
int stack_size = 0;

int get_last_stack_value() { return stack[stack_size - 1]; }

void push_to_stack(int value) { stack[stack_size++] = value; }

void pop_stack() { --stack_size; }

void reset_stack() { stack_size = 0; }

int solution(int n_input, int input[][n_input], int n_moves,
             int moves[n_moves]) {
  reset_stack();
  int answer = 0;

  for (size_t i = 0; i < n_moves; ++i) {
    int column = moves[i] - 1;

    for (size_t row = 0; row < n_input; ++row) {
      if (input[row][column] != 0) {
        // found 인형
        int doll = input[row][column];

        if (stack_size == 0 || get_last_stack_value() != doll) {
          push_to_stack(doll);
        } else {
          // 같은 인형 연속해서 발견 후 삭제
          pop_stack();
          answer += 2;
        }

        input[row][column] = 0;
        break;
      }
    }
  }

  return answer;
}
