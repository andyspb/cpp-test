#ifndef _ARRAY_FIND_DUPLICATES_H
#define _ARRAY_FIND_DUPLICATES_H

#include <iostream>

// Given an array of size N in which every number is between 1 and N,
// determine if there are any duplicates in it.
// You are allowed to destroy the array if you like.
// [ I ended up giving about 4 or 5 different solutions for this, each supposedly better than the others ].

namespace find_dup_in_array {
int test() {
  std::cout << "Test: find duplicates in array ----> " << std::endl;
  int a[100], b[100];

  for (int i = 0; i < 100; ++i) {
    a[i] = i;
  }
  a[33] = 22;
  a[11] = 44;
  for (int i = 0; i < 100; ++i) {
    std::cout << a[i] << " ";
  }
  std::endl(std::cout);
  for (int i = 0; i < 100; ++i)
    b[i] = 0;
  for (int i = 0; i < 100; ++i) {
    if (b[a[i]]) {
      std::cout << "\tduplication found a[" << i << "]=" << a[i] << std::endl;
    } else
      b[a[i]] = 1;
  }
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namesapce array_find_duplicates
#endif // _ARRAY_FIND_DUPLICATES_H