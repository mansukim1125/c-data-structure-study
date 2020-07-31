#include <stdlib.h>
#include "stack.h"

int initialize(Stack *const stack, const int capacity) {
    stack -> stack_ptr = 0;
    if ( (stack -> stack_arr = (int *)calloc(capacity, sizeof(int))) == NULL ) {
        stack -> capacity = 0;
        return Failed;
    }
    stack -> capacity = capacity;
    return Success;
}

int push(Stack *const stack, const int *const value) {
    if ( isFull(stack) ) {
        // resize(stack) -> capacity * 2로 realloc
        stack -> stack_arr = (int *)realloc(stack -> stack_arr, sizeof(int) * (stack -> capacity * 2));
        stack -> capacity *= 2;
    }
    stack -> stack_arr[stack -> stack_ptr] = *value;
    stack -> stack_ptr++;
    return Success;
}

int pop(Stack *const stack) {
    if ( isEmpty(stack) ) {
        return Failed;
    }
    stack -> stack_ptr--;
    return stack -> stack_arr[stack -> stack_ptr];
    // return Success;
}

int peek(const Stack *const stack) {
    if ( isEmpty(stack) ) {
        return Failed;
    }
    return stack -> stack_arr[stack -> stack_ptr - 1];
    // return Success;
}

void clear(Stack *const stack) {
    stack -> stack_ptr = 0;
}

int capacity(const Stack *const stack) {
    return stack -> capacity;
}

int size(const Stack *const stack) {
    return stack -> stack_ptr;
}

int isEmpty(const Stack *const stack) {
    return size(stack) <= 0;
}

int isFull(const Stack *const stack) {
    return size(stack) >= capacity(stack);
}

void erase(Stack *const stack) {
    free(stack -> stack_arr);
    stack -> capacity = 0;
    stack -> stack_ptr = 0;
    stack -> stack_arr = NULL;
}

void retrieve(const Stack *const stack) {
  for (int i = 0; i < stack -> stack_ptr; ++i) {
    printf("%d ", stack -> stack_arr[i]);
  }
}