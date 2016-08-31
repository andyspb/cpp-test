// heapsort.h
// author: andrey.krutogolov@gmail.com
// date:   01.04.2013

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <iostream>

namespace heapsort {

template<class T>
void downheap(T arr[], long k, long n) {
  T new_elem;
  long child;
  new_elem = arr[k];

  while (k <= n / 2) {
    child = 2 * k;
    if (child < n && arr[child] < arr[child + 1]) {
      child++;
    }
    if (new_elem >= arr[child]) {
      break;
    }
    arr[k] = arr[child];
    k = child;
  }
  arr[k] = new_elem;
}

template<class T>
void heapsort(T a[], long size) {
  long i;
  T temp;
  for (i = (size >> 1); i >= 0; --i) {
    downheap(a, i, size - 1);
  }

  for (i = size - 1; i > 0; --i) {
    temp = a[i];
    a[i] = a[0];
    a[0] = temp;
    downheap(a, 0, i - 1);
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  const int size = 11;
  int arr[size] = { 13, 2, 3, 1, 7, 8, 9, 11, 6, 5, 4 };
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::endl(std::cout);
  heapsort<int>(arr, size);
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::endl(std::cout);
  RETURN_OK();
}

}  // namespace heapsort

#endif  // HEAPSORT_H_
