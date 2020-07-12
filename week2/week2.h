#ifndef WEEK2_H
#define WEEK2_H

#include <stdbool.h>

// Search a key in the matrix (height x width)
//
// time complexity O(height * log(width))
// space complexity O(1)
bool binary_search(int* matrix, int height, int width, int key);


// Search a key in the matrix (height x width)
//
// 1. Start from top right
// 2. Repeat
// - move left until x <= key
// - move down until key <= x
//
// For example, search 2
//         v
// [ 1 3 4 5 ]
// [ 2 5 6 7 ]
//
//   v
// [ 1 3 4 5 ]
// [ 2 5 6 7 ]
//
// [ 1 3 4 5 ]
//   v
// [ 2 5 6 7 ]
//
//
// time complexity O(height + width)
// space complexity O(1)
bool linear_search(int* matrix, int height, int width, int key);

#endif
