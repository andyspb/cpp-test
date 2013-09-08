#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>

namespace quicksort {
void qsort(int *arr, int start, int end) {
  if (start >= end)
    return;
  int i(start), j(end), p(start - (start - end) / 2);
  while (i < j) {
    while (i < p && arr[i] <= arr[p])
      i++;
    while (j > p && arr[j] >= arr[p])
      j--;
    if (i < j) {
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
    if (p == j) {
      p = i;
    } else if (p == i) {
      p = j;
    }
  }
  qsort(arr, start, p);
  qsort(arr, p + 1, end);
}

int test() {
  std::cout << "Test: QuickSort --->" << std::endl;
  int arr[] = { 44, -2, 0, 10, 1, 23, 4, 4, 3, 4, 2, 11, 67, -1, 23 };
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);
  qsort(arr, 0, size - 1);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "<--- test passed " << std::endl;
  return 1;
}
} // namespace quicksort

#endif // _QUICKSORT_H_
