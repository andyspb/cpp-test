#ifndef _VIRT_FUNC_2_H_
#define _VIRT_FUNC_2_H_

#include <iostream>

namespace virt_func_2 {
class A {
  public:
    virtual ~A() {
      cout << "A::~A()" << endl;
    }
  public:
    virtual void test() {
      cout << "A::test()" << endl;
    }
};
class B: virtual public A {
  public:
    virtual ~B() {
      cout << "B::~B()" << endl;
    }
    void test() {
      cout << "B::test()" << endl;
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
} // namespace virt_func_2

#endif // #define _VIRT_FUNC_2_H_

