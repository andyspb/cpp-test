#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

#include <iostream>

// bubblesort implementation

namespace bubblesort {

void swap(int& a, int& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int test() {
  std::cout << "Test: bubble sort " << std::endl;
  int arr[] = { 44, -2, 0, 10, 1, 23, 4, 4, 3, 4, 2, 11, 67, -1, 23 };
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (arr[j + 1] < arr[j]) {
        swap(arr[j + 1], arr[j]);
      }
    }
  }

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);
  std::cout << "<--- passed" << std::endl;
  return 1;
}

}  // namespace bubblesort

#endif //_BUBBLESORT_H
