#include <iostream>
namespace virt_access {
class Base {
 public:
  virtual ~Base() {
  }
  virtual void f() {
    std::cout << __FUNCTION__ << std::endl;
  }
};

class Derived : public Base {
 public:
  virtual ~Derived() {
  }
 private:
  void f() {
    std::cout << __FUNCTION__ << std::endl;
  }
};

int test() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  Derived dobj;
  Base* bptr = &dobj;
  // D* dptr = &dobj;

  // valid, virtual B::f() is public,
  // D::f() is called
  bptr->f();

  // error, D::f() is private
  //dptr->f();
  return 1;
}
}
