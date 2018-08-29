#ifndef VIRT_FUNC_6_H_
#define VIRT_FUNC_6_H_

#include <iostream>

namespace virt_func_6 {
class Base {
 public:
  virtual ~Base() {
  }
  virtual void show() {
    std::cout << "From Base::show()" << std::endl;
  }    //(A)
};
class Derived : public Base {
 public:
  virtual ~Derived() {
  }
  virtual void show() {
    std::cout << "From Derived::show" << std::endl;
  }    //(B)
};
class Test {
 public:
  void f(Base* base) {
    std::cout << "\tfrom Test::f(Base*)" << std::endl;
    base->show();
  }
  void f(Derived* derived) {
    std::cout << "\tfrom Test::f(Derived*)" << std::endl;
    derived->show();
  }
};

void allocateme(int* p) {
  p = new int;
  *p = 2;
}

class X {
 public:
  X() {
    std::cout << "X";
  }
  ~X() {
    std::cout << "X";
  }
};
class Y {
 public:
  Y() {
    std::cout << "Y";
  }
  ~Y() {
    std::cout << "Y";
  }
};
class Z : public X {
  Y y;
 public:
  Z() {
    std::cout << "Z";
  }
  ~Z() {
    std::cout << "Z";
  }
};

int test() {
  std::cout << "Test: virtual function 4" << std::endl;
  Base* base = new Base;
  Test* test = new Test;
  base->show();                //(C)
  test->f(base);                //(D)

  Derived* derived = new Derived;
  derived->show();
  test->f(derived);

  std::cout << 5["abcdef"];
  std::endl(std::cout);

  int i = 1;
  allocateme(&i);
  std::cout << i << std::endl;

  Z* z = new Z();
  std::endl(std::cout);
  delete z;
  std::endl(std::cout);

  return 1;
}
}  // namespace virt_func_6

#endif /* VIRT_FUNC_6_H_ */
