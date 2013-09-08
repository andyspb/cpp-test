#ifndef _FIND_LARGEST_SUM_IN_ARRAY_H_
#define _FIND_LARGEST_SUM_IN_ARRAY_H_

//You're given an array containing both positive and negative integers
//and required to find the sub-array with the largest sum (O(N) a la KBL).
//Write a routine in C for the above.

#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <iostream>

namespace find_largest_sum_in_array {
int test() {
  std::cout << "Test: find largest sum in array" << std::endl;

  int s = 5;
  int * int_arr = new int[s];
  int arr[] = { 1, 2, 3, 4, 5 };
  int* int_ptr = NULL;
  int int_val = 8;

  std::cout << "size of int_arr = " << sizeof(int_arr) << std::endl;
  std::cout << "size of arr = " << sizeof(arr) << std::endl;
  std::cout << "length of arr = " << sizeof(arr) / sizeof(arr[0]) << std::endl;
  std::cout << "size of int_ptr = " << sizeof(int_ptr) << std::endl;
  std::cout << "size of int = " << sizeof(int_val) << std::endl;

  int A[] = { 5, -2, 4, 4, -33, 8, -55, 6, -1, 4 };
  int len = sizeof(A) / sizeof(A[0]);
  for (int i = 0; i < len; i++) {
    std::cout << A[i] << " ";
  }
  std::endl(std::cout);
  int sum = 0;
  int minSum = 0;
  int minIndex = -1;
  int subArrStart = 0, subArrEnd = 0;
  int subArrSum = 0;
  for (int i = 0; i < len; i++) {
    sum += A[i];
    if (sum <= minSum) {
      minSum = sum;
      minIndex = i;
    }
    if (sum - minSum > subArrSum) {
      subArrStart = minIndex + 1;
      subArrEnd = i;
      subArrSum = sum - minSum;
    }
  }
  std::cout << "SubArray: [" << subArrStart << ", " << subArrEnd << "] MaxSum: "
      << subArrSum << std::endl;
  return 1;
}
}  // find_largest_sum_in_array

#endif // _FIND_LARGEST_SUM_IN_ARRAY_H_
