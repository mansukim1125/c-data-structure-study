#include "ctest.h"

void assertEqual(const int value, const int expected) {
    if (value == expected) {
        printf("test %d success: result %d is equal to %d.\n", count, value, expected);    
    } else {
        printf("test %d failed: result %d is NOT equal to %d.\n", count, value, expected);    
    }
    count++;
}