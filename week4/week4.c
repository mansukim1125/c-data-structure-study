#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "week4.h"

Queue new_queue() {
  Queue q;
  q.front = q.rear = -1;
  q.capacity = QUEUE_CAPACITY;
  q.data = calloc(QUEUE_CAPACITY, sizeof(int));
  return q;
}

void destroy_queue(Queue* q) { free(q->data); }

bool is_empty(Queue* q) { return q->front == -1; }

int peek(Queue* q) {
  assert(!is_empty(q));
  return q->data[q->front];
}

bool is_full(Queue* q) {
  if (q->front == 0 && q->rear == q->capacity - 1) {
    return true;
  }

  if (q->rear == q->front - 1) {
    return true;
  }

  return false;
}

void push(Queue* q, int value) {
  assert(!is_full(q));

  if (is_empty(q)) {
    q->front = q->rear = 0;
    q->data[q->rear] = value;
  } else {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
  }
}

// If front == rear, it means there is the only one element. Hence, pop and
// reset the front and rear to -1. Otherwise, simply move front.
int pop(Queue* q) {
  assert(!is_empty(q));
  int value = q->data[q->front];

  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }

  return value;
}

size_t size(Queue* q) {
  if (q->front <= q->rear) {
    return q->rear - q->front + 1;
  }
  return q->capacity - (q->front - q->rear - 1);
}

int solve(int n) {
  Queue q = new_queue();
  for (size_t i = 1; i <= n; ++i) {
    push(&q, i);
  }

  while (size(&q) > 1) {
    pop(&q);

    if (size(&q) > 1) {
      push(&q, pop(&q));
    }
  }

  int value = peek(&q);
  destroy_queue(&q);
  return value;
}
