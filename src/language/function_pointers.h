#ifndef FUNCTION_POINTERS
#define FUNCTION_POINTERS

#include <iostream>

namespace function_pointers {

void f() {
  std::cout << "from f()" << std::endl;
}

class A {
  public:
    void f() {
      std::cout << "from A::f()" << std::endl;
    }
    void g(int i) {
      std::cout << "from A::g() i=" << i << std::endl;
    }
};

int test() {
  void (*pf)() = f;
  pf();

  A a;
  void (A::*paf)() = &A::f;
  (a.*paf)();

  void (A::*pag)(int) = &A::g;
  (a.*pag)(10);
  return 1;
}

}  // namespace function_pointers

#endif  // FUNCTION_POINTERS
