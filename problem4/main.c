#include "queue.h"
#include "ctest.h"

void init(Queue *const queue, const int N) {
    int i;
    initialize(queue, N);
    for (i = 1; i <= N; ++i) {
        enque(queue, i);
    }
}

int solution(Queue *const queue) {
    int target;
    while ( size(queue) != 1 ) {
        deque(queue, &target);
        deque(queue, &target);
        enque(queue, target);
    }
    return target;
}

int main(void) {
    {
        int result;
        Queue q;

        init(&q, 4);

        result = solution(&q);
        assertEqual(result, 4);

        erase(&q);
    }
    {
        int result;
        Queue q;

        init(&q, 6);

        result = solution(&q);
        assertEqual(result, 4);

        erase(&q);
    }

    return 0;
}