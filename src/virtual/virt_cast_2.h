#ifndef _VIRT_CAST_2_H_
#define _VIRT_CAST_2_H_

#include <iostream>
#include <assert.h>
namespace virt_cast_2 {
class Base {
  public:
    Base() {
      std::cout << "from A" << std::endl;
    }
    virtual ~Base() {
      std::cout << "delete Base" << std::endl;
    }
};
class Derived: public Base {
  public:
    Derived() {
      std::cout << "from Derived" << std::endl;
    }
    ~Derived() {
      std::cout << "delete Derived" << std::endl;
    }
};

int test() {
  std::cout << "Test: Dynamic cast --->" << std::endl;
  Base * a = new Base();
  Derived * b = dynamic_cast<Derived*>(a);
  assert(a);
  delete (b);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // virt_cast_2

#endif // _VIRT_CAST_2_H_
