#include "queue.h"

int initialize(Queue *const queue, const int capacity) {
    queue -> size = 0;
    queue -> front = 0;
    queue -> rear = 0;
    if ((queue -> arr = (int *)calloc(capacity, sizeof(int))) == NULL) {
        queue -> capacity = 0;
        return -1;
    }
    queue -> capacity = capacity;
    return 0;
}

int enque(Queue *const queue, const int data) {
    if ( isFull(queue) ) return -1;
    queue -> arr[queue -> rear] = data;
    queue -> rear = (queue -> rear + 1) % queue -> capacity;
    queue -> size++;
    return 0;
}

int deque(Queue *const queue, int *const target) {
    if ( isEmpty(queue) ) return -1;
    *target = queue -> arr[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> size--;
    return 0;
}

int size(const Queue *const queue) {
    return queue -> size;
}

int isFull(const Queue *const queue) {
    return size(queue) >= queue -> capacity;
}

int isEmpty(const Queue *const queue) {
    return size(queue) <= 0;
}

void erase(Queue *const queue) {
    queue -> capacity = 0;
    queue -> size = 0;
    queue -> front = 0;
    queue -> rear = 0;
    free(queue -> arr);
}