#ifndef _TEMPLATE_FACTORIAL_H_
#define _TEMPLATE_FACTORIAL_H_

#include <iostream>

namespace template_factorial {

template<int n>
struct Factorial {
    enum {
      value = n * Factorial<n - 1>::value
    };
};

template<>
struct Factorial<0> {
    enum {
      value = 1
    };
};

int test() {
  std::cout << "Test: template factorial --->" << std::endl;
  int x = Factorial<4>::value;  // == 24
  int y = Factorial<0>::value;  // == 1
  std::cout << "\t4!=" << x << std::endl;
  std::cout << "\t0!=" << y << std::endl;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace template_factorial

#endif //  _TEMPLATE_FACTORIAL_H_
