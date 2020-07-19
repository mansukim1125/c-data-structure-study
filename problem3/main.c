#include <stdio.h>
#include "stack.h"
#include "ctest.h"

int solution(int **board, const int board_width, int *moves, const int moves_width) {
    int **arr = (int **)calloc(board_width, sizeof(int *)); // 2 dimensional array pointer.
    Stack *stacks = (Stack *)calloc(board_width, sizeof(Stack)); // create stacks store board items.
    Stack basket; // stack to store popped at stacks.
    int result = 0; // count of popped from basket.
    int stack_top, basket_top, crane_index;
    for (int i = 0; i < board_width; ++i) {
        arr[i] = (int *)board + board_width * i;
    }

    // transpose items in board
    for (int i = 0; i < board_width; ++i) {
        initialize(&stacks[i], board_width);
        for (int j = 0; j < board_width; ++j) {
            if (arr[board_width - j - 1][i] == 0) break;
            push(&stacks[i], &arr[board_width - j - 1][i]);
        }
    }

    initialize(&basket, 10);

    for (int i = 0; i < moves_width; ++i) {
        crane_index = moves[i] - 1;
        stack_top = pop(&stacks[crane_index]);
        if ( !isEmpty(&basket) && stack_top == peek(&basket) ) {
            pop(&basket);
            result += 2;
        } else if (stack_top != -1) { // if stack is empty, stack_top == -1.
            push(&basket, &stack_top);
        }
    }

    for (int i = 0; i < board_width; ++i) {
        erase(&stacks[i]);
    }
    free(arr);
    free(stacks);

    return result;
}

int main(void) {
    { // test 1.
        int board[][5] = {
            { 0, 0, 0, 0, 0 },
            { 0, 0, 1, 0, 3 },
            { 0, 2, 5, 0, 1 },
            { 4, 2, 4, 4, 2 },
            { 3, 5, 1, 3, 1 }
        };
        int moves[] = { 1, 5, 3, 5, 1, 2, 1, 4 };

        int res = solution((int **)board, 5, moves, 8);

        assertEqual(res, 4);
    }
    { // test 2.
        int board[][6] = {
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 7, 0 },
            { 0, 0, 0, 0, 8, 0 },
            { 0, 0, 0, 8, 6, 7 },
            { 0, 3, 6, 7, 7, 2 },
            { 1, 2, 5, 3, 3, 1 },
        };
        int moves[] = { 1, 6, 5, 2, 4, 2, 6, 3, 2, 1, 4, 6 };
        int res = solution((int **)board, 6, moves, 12);

        assertEqual(res, 4);
    }
    { // test 3.
        int board[][7] = {
            { 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 2, 0, 2, 0, 8 },
            { 0, 1, 4, 0, 4, 0, 9 },
            { 0, 5, 6, 3, 3, 7, 4 },
            { 3, 1, 4, 2, 1, 5, 3 },
            { 2, 3, 2, 1, 2, 6, 7 },
            { 3, 1, 2, 1, 3, 4, 4 }
        };
        int moves[] = { 5, 1, 3, 7, 2, 4, 3, 4, 5, 1, 7, 6, 1, 3, 2 };
        int res = solution((int **)board, 7, moves, 15);

        assertEqual(res, 0);
    }

    return 0;
}