#ifndef _VIRT_FUNC_4_H_
#define _VIRT_FUNC_4_H_

#include <iostream>

namespace virt_func_4 {
struct Base {
    virtual ~Base() {}
    virtual void f() {
      std::cout << "Class Base" << std::endl;
    }
};

struct DerivedA: Base {
    virtual ~DerivedA() {}
    void f(int) {
      std::cout << "Class DerivedA" << std::endl;
    }
};

struct DerivedB: DerivedA {
    virtual ~DerivedB() {}
    void f() {
      std::cout << "Class DerivedB" << std::endl;
    }
};

int test() {
  std::cout << "Test: virtual function 4" << std::endl;
  Base base;
  DerivedB derivedB;
  DerivedA* derivedA = &derivedB;
  Base* base1 = &derivedB;
  //b.f(1);
//  derivedA->f(); // incorrect
  derivedA->f(1);
  base1->f();
  std::cout << "<--- test passed";
  return 1;
}
} // namespace virt_func_4

#endif // _VIRT_FUNC_4_H_
