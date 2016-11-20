#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <iostream>

namespace quicksort {

template<typename T>
void print_array(T* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void quicksort(int *arr, int start, int end) {
  if (start >= end)
    return;
  int i(start), j(end), p(start - (start - end) / 2);
  while (i < j) {
    while (i < p && arr[i] <= arr[p])
      ++i;
    while (j > p && arr[j] >= arr[p])
      --j;
    if (i < j) {
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }

    if (p == i)
      p = j;
    else if (p == j)
      p = i;
  }
  quicksort(arr, start, p);
  quicksort(arr, p + 1, end);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  int arr[] = { 44, -2, 0, 10, 1, 23, 4, 4, 3, 4, 2, 11, 67, -1, 23 };
  int size = sizeof(arr) / sizeof(arr[0]);
  print_array(arr, size);
  quicksort(arr, 0, size-1);
  print_array(arr, size);
  RETURN_OK();
}
}  // namespace quicksort

#endif // _QUICKSORT_H_
