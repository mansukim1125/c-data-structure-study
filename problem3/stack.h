#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

enum Status {
    Success = 0,
    Failed = -1
};

typedef struct STACK {
    int capacity;
    int stack_ptr;
    int *stack_arr;
} Stack;

int initialize(Stack *const stack, const int capacity);

int push(Stack *const stack, const int *const value);

int pop(Stack *const stack);

int peek(const Stack *const stack);

void clear(Stack *const stack);

int capacity(const Stack *const stack);

int size(const Stack *const stack);

int isEmpty(const Stack *const stack);

int isFull(const Stack *const stack);

void erase(Stack *const stack);

void retrieve(const Stack *const stack);

#endif