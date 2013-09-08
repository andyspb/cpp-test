#ifndef _BINARY_H_
#define _BINARY_H_

#include <iostream>
namespace binary {
void binary(int num) {
  if (num < 0) {
    std::cout << "Value less or equal zero: " << num << std::endl;
    return;
  } else if (num == 0) {
    return;
  } else {
    int reminder = num % 2;
    binary(num >> 1);
    std::cout << reminder;
  }
}

int test() {
  std::cout << "Test: Binary view of int --->" << std::endl;
  for (int i = 1; i < 100; i += 15) {
    std::cout << "Integer:" << i << " binary: ";
    binary(i);
    std::endl(std::cout);
  }
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace binary

#endif //  _BINARY_H_
