#include <stdio.h>
/*
m * n 배열에서 특정한 값의 존재 여부를 반환하는 함수를 작성하세요.
1. 한 행의 숫자들은 오름차순(left to right)으로 정렬되어 있습니다.
2. 한 열의 숫자들은 오름차순(top to bottom)으로 정렬되어 있습니다.
*/

int binarySearch(const int *arr, const int size, const int key) {
    int left = 0, right = size - 1;
    int middle;
    while(left <= right) {
        middle = left + (right - left) / 2; // prevent overflow left + right.
        switch (key > arr[middle] ? -1 : key < arr[middle] ? 1 : 0) {
            case -1: left = middle + 1; break;
            case 1: right = middle - 1; break;
            case 0: return 1;
        }
    }
    return 0;
}

int searchMatrix(const int matrix[][5], const int row_size, const int col_size, const int key) {
    int i;
    for(i = 0; i < row_size; ++i) {
        if(binarySearch(matrix[i], col_size, key)) return 1;
    }
    return 0;
}

int main(void) {
    int arr[][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int row_size = sizeof(arr) / sizeof(arr[0]);
    int col_size = sizeof(arr[0]) / sizeof(arr[0][0]);

    int result = searchMatrix(arr, row_size, col_size, 5);
    
    printf(result ? "true" : "false");

    return 0;
}