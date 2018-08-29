#ifndef _VIRT_INHERITANCE_H_
#define _VIRT_INHERITANCE_H_

#include <iostream>

namespace virt_inheritance {
class Base {
 public:
  virtual ~Base() {
  }
  virtual void f() {
    std::cout << __FUNCTION__ << std::endl;
  }
};

class DerivedA : public Base {
 public:
  virtual ~DerivedA() {
  }
  void f() {
    std::cout << __FUNCTION__ << std::endl;
  }
};

class DerivedB : public Base {
 public:
  virtual ~DerivedB() {
  }
  void f() {
    std::cout << __FUNCTION__ << std::endl;
  }
};

// Error:
// Both A::f() and B::f() try to override V::f()
class DerivedC : public DerivedA, public DerivedB {
};

int test() {
  DerivedC d;
  //V* vptr = &d;
  DerivedA* a = &d;
  Base* v = a;
  v->f();
  a->f();
  //	// which f(), A::f() or B::f()?
  //	vptr->f();
  std::cout << "<--- test passed";
  return 1;
}
}  // namespace virt_inheritance

#endif // #define _VIRT_INHERITANCE_H_
