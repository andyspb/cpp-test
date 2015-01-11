#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <iostream>

namespace merge_sort {
void merge(int* arr, int lb, int p, int ub) {
  int p1 = lb, p2 = p + 1, p3 = 0;
  int * a = new int[ub - lb + 1];
  while (p1 <= p && p2 <= ub) {
    a[p3++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
  }
  while (p2 <= ub) {
    a[p3++] = arr[p2++];
  }
  while (p1 <= p) {
    a[p3++] = arr[p1++];
  }
  for (int i = 0; i < ub - lb + 1; i++) {
    arr[lb + i] = a[i];
  }
  delete[] a;
}

void msort(int* arr, int lb, int ub) {
  if (lb < ub) {
    int p = lb - (lb - ub) / 2;
    msort(arr, lb, p);
    msort(arr, p + 1, ub);
    merge(arr, lb, p, ub);
  }
}

int test() {
  std::cout << "Test: mergesort ---> " << std::endl;
  int arr[] = { 44, -2, 0, 10, 1, 23, 4, 4, 3, 4, 2, 11, 67, -1, 23 , 43};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);
  msort(arr, 0, size - 1);
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);
  return 1;
}
} // namespace merge_sort

#endif // _MERGE_SORT_H_
