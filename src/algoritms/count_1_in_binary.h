#ifndef _COOUNT_ONES_IN_BINARY_H_
#define _COOUNT_ONES_IN_BINARY_H_

#include <iostream>
//Give a very good method to count the number of ones in a "n" (e.g. 32) bit number.

namespace count_ones_in_binary {

int number_of_ones_in_N(int b) {
  printf(" %d has", b);
  int n = 0;
  for (n = 0; b; ++n) {
    b &= b - 1;
  }
  printf(" %d ones\n", n);
  return n;
}

int NumberOfSetBits(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int test() {
  std::cout << "Test: count ones in binary:" << std::endl;
  std::cout
      << "Give a very good method to count the number of ones in a N (e.g. 32) bit number."
      << std::endl;
  number_of_ones_in_N(0);
  number_of_ones_in_N(1);
  number_of_ones_in_N(2);
  number_of_ones_in_N(3);
  number_of_ones_in_N(7);
  number_of_ones_in_N(8);
  number_of_ones_in_N(45);
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namespace count_ones_in_binary
#endif // _COOUNT_ONES_IN_BINARY_H_
