#ifndef WEEK4_WEEK4_H
#define WEEK4_WEEK4_H
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 500000

// Circular queue
typedef struct {
  int front;
  int rear;
  int capacity;
  int* data;
} Queue;

// Initialize the Queue
Queue new_queue();

// Free Queue.data
void destroy_queue(Queue* q);
bool is_empty(Queue* q);
// Returns the first value of Queue
int peek(Queue* q);
bool is_full(Queue* q);
void push(Queue* q, int value);
int pop(Queue* q);
size_t size(Queue* q);


// Use a queue and then run the simulation.
//
// Pop the first element.
//
// if the number of remaining elmenets is greater than 1,
// Pop the first element again and push to the second
//
// repeat until there is a single element in the queue.
int solve(int N);

#endif  // WEEK4_WEEK4_H
