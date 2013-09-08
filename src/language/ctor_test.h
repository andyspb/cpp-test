#ifndef _CTOR_TEST_H_
#define _CTOR_TEST_H_

#include <iostream>

namespace ctor_test {
class A {
 public:
  A(int c = 0)
      : a(c) {
    std::cout << "From A::A()  a = " << a << std::endl;
  }
  ~A() {
  }
 private:
  int a;
};

int test() {
  A a;
  //A a=A();
  return 1;
}
}  // namespace ctor_test

#endif  //  _CTOR_TEST_H_
