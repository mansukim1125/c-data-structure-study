#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* buffer;
  int front;
  int rear;
  int capacity;
} Queue;

Queue new_queue() {
  Queue q;
  q.front = -1;
  q.rear = -1;
  q.buffer = (int*)calloc(500000, sizeof(int));
  q.capacity = 500000;
  return q;
}

int size(Queue* q) {
  if (q->front <= q->rear) {
    return q->rear - q->front + 1;
  }

  return q->capacity - (q->front - q->rear - 1);
}

void destroy_queue(Queue* q) { free(q->buffer); }

bool is_empty(Queue* queue) { return queue->front == -1; }

bool is_full(Queue* queue) {
  if (queue->front == 0 && queue->rear == queue->capacity - 1) {
    return true;
  }

  if (queue->rear == (queue->front - 1) % (queue->capacity - 1)) {
    return true;
  }

  return false;
}

int front(Queue* queue) {
  assert(!is_empty(queue));
  return queue->buffer[queue->front];
}

int deque(Queue* queue) {
  assert(!is_empty(queue));
  int data = queue->buffer[queue->front];

  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else if (queue->front == queue->capacity - 1) {
    queue->front = 0;
  } else {
    (queue->front)++;
  }

  return data;
}

void enque(Queue* queue, int value) {
  assert(!is_full(queue));

  if (queue->front == -1) {
    queue->front = queue->rear = 0;
    queue->buffer[queue->rear] = value;
  } else if (queue->rear == queue->capacity - 1 && queue->front != 0) {
    queue->rear = 0;
    queue->buffer[queue->rear] = value;
  } else {
    queue->buffer[++(queue->rear)] = value;
  }
}

int solve(int n) {
  Queue q = new_queue();

  for (size_t i = 1; i <= (size_t)n; ++i) {
    enque(&q, i);
  }

  while (size(&q) > 1) {
    deque(&q);
    if (size(&q) > 1) {
      enque(&q, deque(&q));
    }
  }

  int answer = front(&q);
  destroy_queue(&q);

  return answer;
}

int main(void) {
  int N;
  scanf("%d", &N);
  printf("%d\n", solve(N));
  return 0;
}
