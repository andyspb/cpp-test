/*
 * selection_sort.h
 *
 *  Created on: 25 џэт. 2015 у.
 *      Author: andy
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <iostream>

namespace selection_sort {

template<class T>
void swap(T *xp, T *yp) {
  T temp = *xp;
  *xp = *yp;
  *yp = temp;
}

template<class T>
void selectionSort(T arr[], int n) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; ++i) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; ++j)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    swap(&arr[min_idx], &arr[i]);
  }
}

/* Function to print an array */
template<class T>
void printArray(T arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::endl(std::cout);
}

// Driver program to test above functions
TEST_RESULT test() {
  __SCOPE_LOG__;
  int arr[] = { 64, 25, 12, 22, 11 };
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Unsorted array:" << std::endl;
  printArray(arr, n);

  selectionSort(arr, n);

  std::cout << "Sorted array:" << std::endl;
  printArray(arr, n);
  RETURN_OK();
}
}

#endif /* SELECTION_SORT_H_ */
