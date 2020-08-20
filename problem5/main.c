#include <stdio.h>
#include <stdlib.h>

void print(const int N, char **const arr, const int x, const int y) {
    int i, j;
    if (N == 1) {
        arr[y][x] = '*';
        return;
    }
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) continue;
            print(N / 3, arr, x + N / 3 * j, y + N / 3 * i);
        }
    }
}

void printArray(char **const arr, const int size) {
    int i, j;

    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            putchar(arr[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int i, j, N;
    
    scanf("%d", &N);

    char **arr = (char **)calloc(N, sizeof(char *));
    for (i = 0; i < N; ++i) {
        arr[i] = (char *)calloc(N, sizeof(char));
        for (j = 0; j < N; ++j) {
            arr[i][j] = ' ';
        }
    }

    print(N, arr, 0, 0);

    printArray(arr, N);

    for (i = 0; i < N; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}