#include <iostream>

bool IsPowerOfTwo(unsigned long x) {
  if (x <= 0) {
    return false;
  }
  std::cout << "x= " << x << " ";
  if ((x & (x - 1)) == 0) {
    std::cout << "is power of 2\n";
    return true;
  } else {
    std::cout << "is not power of 2\n";
    return false;
  }
}
