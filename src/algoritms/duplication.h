#ifndef _DUPLICATION_H
#define _DUPLICATION_H

#include <iostream>
//Given an array of size N in which every number is between 1 and N,
//determine if there are any duplicates in it.
//You are allowed to destroy the array if you like.
//[ I ended up giving about 4 or 5 different solutions for this, each supposedly better than the others ].

namespace duplication {
int test() {
  std::cout << "Test: Duplication test --->" << std::endl;
  int a[100], b[100];

  for (int i = 0; i < 100; i++) {
    a[i] = i;
  }
  a[33] = 22;
  a[11] = 44;
  for (int i = 0; i < 100; ++i) {
    b[i] = 0;
  }
  for (int i = 0; i < 100; ++i) {
    if (b[a[i]]) {
      std::cout << "duplication found a[" << i << "]=" << a[i] << std::endl;
    } else
      b[a[i]] = 1;
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace duplication

#endif //_DUPLICATION_H
