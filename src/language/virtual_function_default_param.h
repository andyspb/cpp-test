#ifndef _VIRTUAL_FUNCTION_DEFAULT_PARAM_H_
#define _VIRTUAL_FUNCTION_DEFAULT_PARAM_H_

#include <iostream>

namespace virtual_function_default_param {

class Base {
 public:
  virtual ~Base() {
  }
  virtual int shift(int n = 2) const {
    std::cout << "from Base::shift()" << std::endl;
    return n;
  }
};

class Derived : public Base {
 public:
  virtual ~Derived() {
  }
  int shift(int n = 5) const {
    std::cout << "from Derived::shift()" << std::endl;
    return n;
  }
};

int test() {
  std::cout << "Test from interview ---> " << std::endl;
  Derived d;
  Base *b = &d;

  std::cout << b->shift() << std::endl;

  return 1;
}
}  // virtual_function_default_param

#endif // _VIRTUAL_FUNCTION_DEFAULT_PARAM_H_
