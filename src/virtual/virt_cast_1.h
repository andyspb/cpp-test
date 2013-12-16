#ifndef _VIRT_CAST_1_H_
#define _VIRT_CAST_1_H_

#include <iostream>

namespace virt_cast_1 {

class Base {
 public:
  virtual ~Base() {
    std::cout << "From Base::~Base()" << std::endl;
  }
  virtual void f() {
    std::cout << "From Base::f()" << std::endl;
  }
};
class Derived : public Base {
 public:
  virtual ~Derived() {
    std::cout << "From Derived::~Derived()" << std::endl;
  }
  virtual void f() {
    std::cout << "From Derived::f()" << std::endl;
  }
};

int test() {
  std::cout << "Test: Dynamic cast --->" << std::endl;
//  Base* pb = new Derived();   // unclear but ok
//  Base* pb2 = new Base();
//  Derived* pd = dynamic_cast<Derived*>(pb);   // ok: pb actually points to a D
//  pd->f();
//  Derived* pd2 = dynamic_cast<Derived*>(pb2);   // pb2 points to a B not a D
//  pd2->f();
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace virt_cast_1

#endif // _VIRT_CAST_1_H_
