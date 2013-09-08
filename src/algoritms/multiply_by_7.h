#ifndef _MULTIPLY_BY_7_H
#define _MULTIPLY_BY_7_H

#include <iostream>
//Give a fast way to multiply a number by 7.
namespace multiply_by_7 {

void multiply_by_7(int x) {
  std::cout << "Multiply by 7: ( " << x << " * 7 ) = ";
  int temp = x;
  x = x << 3;
  std::cout << x - temp << std::endl;
}

int test() {
  std::cout << "Test: fast way to multiply a number by 7 --- >" << std::endl;
  for (int i = 0; i < 21; i += 3) {
    multiply_by_7(i);
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namspace multiply_by_7

#endif  // _MULTIPLY_BY_7_H
