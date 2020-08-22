#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct POINT {
	int x, y;
} Point;

int compare(const Point *const p1, const Point *const p2) {
	return p1 -> x > p2 -> x ? 1 : p1 -> x < p2 -> x ? -1 : p1 -> y > p2 -> y ? 1 : p1 -> y < p2 -> y ? -1 : 0;
}

void quick_sort(Point *const arr, const int start, const int end) {
	Point pivot, temp;
	int left, right;
	if (start < end) {
		left = start, right = end;
		memcpy(&pivot, &arr[left], sizeof(Point));
		do {
			while (!compare(&arr[left], &pivot)) left++;
			while (compare(&arr[right], &pivot)) right--;
			if (left < right) {
				memcpy(&temp, &arr[left], sizeof(Point));
				memcpy(&arr[left], &arr[right], sizeof(Point));
				memcpy(&arr[right], &temp, sizeof(Point));
			}
		} while (left < right);
		memcpy(&temp, &arr[left], sizeof(Point));
		memcpy(&arr[left], &arr[right], sizeof(Point));
		memcpy(&arr[right], &temp, sizeof(Point));
		quick_sort(arr, start, right - 1);
		quick_sort(arr, right + 1, end);
	}
}

int main(void) {
	int i, N;
	Point *point_arr;
	
	scanf("%d", &N);

	point_arr = (Point *)calloc(N, sizeof(Point));

	for (i = 0; i < N; ++i) {
		scanf("%d %d", &point_arr[i].x, &point_arr[i].y);
	}

	quick_sort(point_arr, 0, N - 1);

	for (i = 0; i < N; ++i) {
		printf("%d %d\n", point_arr[i].x, point_arr[i].y);
	}

	free(point_arr);

    return 0;
}
