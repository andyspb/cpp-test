#ifndef _VIRT_FUNC_2_H_
#define _VIRT_FUNC_2_H_

#include <iostream>

namespace virt_func_2 {
class A {
 public:
  virtual ~A() {
    std::cout << "A::~A()" << std::endl;
  }
 public:
  virtual void test() {
    std::cout << "A::test()" << std::endl;
  }
};
class B : virtual public A {
 public:
  virtual ~B() {
    std::cout << "B::~B()" << std::endl;
  }
  void test() {
    std::cout << "B::test()" << std::endl;
  }
};

int test() {
  std::cout << "Test: Virtual function 2 --->" << std::endl;
  A * a = new B();
  a->test();
  delete a;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace virt_func_2

#endif // #define _VIRT_FUNC_2_H_

