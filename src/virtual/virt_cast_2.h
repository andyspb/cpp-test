#ifndef _VIRT_CAST_2_H_
#define _VIRT_CAST_2_H_

#include <iostream>
#include <assert.h>
using namespace std;
namespace virt_cast_2 {
class Base {
  public:
    Base() {
      cout << "from A\n";
    }
    virtual ~Base() {
      cout << "delete Base\n";
    }
};
class Derived: public Base {
  public:
    Derived() {
      cout << "from Derived\n";
    }
    ~Derived() {
      cout << "delete Derived\n";
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
