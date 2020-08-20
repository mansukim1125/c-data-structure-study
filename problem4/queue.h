#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct QUEUE {
    int capacity;
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

int initialize(Queue *const queue, const int capacity);

int enque(Queue *const queue, const int data);

int deque(Queue *const queue, int *const target);

int size(const Queue *const queue);

int isFull(const Queue *const queue);

int isEmpty(const Queue *const queue);

void erase(Queue *const queue);

#endif