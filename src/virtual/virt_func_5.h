#ifndef VIRT_TEST_5_H_
#define VIRT_TEST_5_H_

#include <iostream>
namespace virt_func_5 {
struct A {
  virtual ~A() {
  }
  virtual void f() {
    std::cout << "Class A" << std::endl;
  }
};

struct B : A {
  virtual ~B() {
  }
  void f() {
    std::cout << "Class B" << std::endl;
  }
};

void g(A& arg) {
  arg.f();
}
int test() {
  std::cout << "Test: virtual function 5" << std::endl;
  B x;
  g(x);
  return 1;
}
}  // namespace virt_func_5

#endif /* VIRT_TEST_5_H_ */
