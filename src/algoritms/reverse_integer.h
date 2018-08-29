#ifndef _REVERSE_INTEGER_H_
#define _REVERSE_INTEGER_H_

//method to reverse an integer.
#include <iostream>

namespace reverse_integer {

int ReverseInteger(int n) {
  int sum = 0;
  int rem;
  while (n > 0) {
    rem = n % 10;
    sum = sum * 10 + rem;
    n = n / 10;
  }
  return sum;
}

int test(int value) {
  std::cout << "Reverse integer test " << std::endl;
  int reversedInteger = ReverseInteger(value);
  std::cout << "integer before reverse: " << value << " reversedInteger: "
            << reversedInteger << std::endl;
  return 1;
}
}  // namespace reverse_integer
#endif // _REVERSE_INTEGER_H_
