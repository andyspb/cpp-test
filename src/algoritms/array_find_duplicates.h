#ifndef _ARRAY_FIND_DUPLICATES_H
#define _ARRAY_FIND_DUPLICATES_H

#include "../common/templates.h"

#include <iostream>
#include <algorithm>

// Given an array of size N in which every number is between 1 and N,
// determine if there are any duplicates in it.
// You are allowed to destroy the array if you like.
// [ I ended up giving about 4 or 5 different solutions for this, each supposedly better than the others ].

namespace find_dup_in_array {
template <typename T>
void print_array(T* arr, size_t size) {
  for (size_t s=0; s<size; ++s) {
    std::cout << arr[s] << " ";
  }
  std::endl(std::cout);
}


int find_duplicates_in_array() {
  __SCOPE_LOG__;
  LOG(INFO) << "Test: find duplicates in array";

  int a[100], b[100] = {0};
  for (int i = 0; i < 100; ++i) {
    a[i] = i;
  }
  // set dups
  a[33] = 22, a[11] = 44;
  print_array(a, sizeof_array(a));
  print_array(b, sizeof_array(b));
  for (int i = 0; i < 100; ++i) {
    if (b[a[i]]) {
      std::cout << "duplication found a[" << i << "]=" << a[i] << std::endl;
    } else
      b[a[i]] = 1;
  }
  return 1;
}

int find_duplicates_in_array_2(int a[], size_t a_size) {
  __SCOPE_LOG__;
  LOG(INFO) << "Test: find duplicates in array";

  int* b = new int[a_size];
  std::fill_n(b, a_size, 0);
  print_array(a, a_size);
  print_array(b, a_size);
  for (size_t i = 0; i < a_size; ++i) {
    if (b[a[i]]) {
      std::cout << "duplication found a[" << i << "]=" << a[i] << std::endl;
    } else
      b[a[i]] = 1;
  }
  delete[] b;
  return 1;
}


TEST_RESULT test() {
  __SCOPE_LOG__;


  find_duplicates_in_array();

  int a[10] = {1,2,3,3,3,4,4,4,8,9};
  size_t size = sizeof_array(a);
  LOG(INFO) << "size=" << size;

  find_duplicates_in_array_2(a, sizeof_array(a));

  RETURN_OK();
}

}  // namesapce array_find_duplicates
#endif // _ARRAY_FIND_DUPLICATES_H