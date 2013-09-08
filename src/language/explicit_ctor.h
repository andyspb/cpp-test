#ifndef _EXPLICIT_CTOR_H_
#define _EXPLICIT_CTOR_H_

#include <iostream>

namespace explicit_ctor {
class A {
  public:
    A() {
    }
    explicit A(int a) {
      std::cout << "explicit Constructor called" << std::endl;
      std::cout << "value is:" << a << std::endl;
    }
};

int test() {
  std::cout << "Test: Explicit Constructor example --->" << std::endl;
  A a = 1;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}

}  // namespace explicit_ctor

#endif // _EXPLICIT_CTOR_H_
