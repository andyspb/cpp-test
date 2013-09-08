#ifndef _VIRT_FUNC_3_H_
#define _VIRT_FUNC_3_H_

#include <iostream>

namespace virt_func_3 {
class Base {
  public:
    Base() {}
    virtual ~Base() {}
    virtual void doSome() {
      std::cout << "From Base::doSome()" << std::endl;
    }
};

class Derived: public Base {
  public:
    Derived() {
      doSome();
    }
    virtual ~Derived() {}
    virtual void doSome() {
      std::cout << "From Derived::doSome()" << std::endl;
    }
};

int test() {
  std::cout << "Test: virtual function 3" << std::endl;
  Base * b = new Derived();
  delete (b);
  std::cout << "<--- test passed";
  return 1;
}
} // virt_func_3

#endif // #ifndef _VIRT_FUNC_3_H_
