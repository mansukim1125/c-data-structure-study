#include <stdio.h>
#include <stdlib.h>

void spiral_array(int **arr, int n) {
    /*
    *   x, y는 배열의 좌표를 표현.
    *   value는 배열에 들어갈 값을 표현.
    *   inc는 x, y의 증가량을 표현. (1은 증가, -1은 감소)
    *   x 증가, y 증가, x감소, y감소 순으로 진행.
    */

    int i, x = 0, y = 0, value = 1, inc = 1;
    
    while(n) {
        for(i = 0; i < n; ++i, x += inc) {
            arr[y][x] = value++;
        } x += inc * -1, y += inc;
        for(i = 0; i < n - 1; ++i, y += inc) {
            arr[y][x] = value++;
        } y += inc * -1, x += inc * -1;
        inc *= -1, n = n - 1;
    }
}

int main(void) {
    int i, j, size;
    int **arr;

    scanf("%d", &size);

    arr = (int **)calloc(size, sizeof(int *));
    for(i = 0; i < size; ++i) {
        arr[i] = (int *)calloc(size, sizeof(int));
    }

    spiral_array(arr, size);

    for(i = 0; i < size; ++i) {
        for(j = 0; j < size; ++j) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < size; ++i) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;

    return 0;
}