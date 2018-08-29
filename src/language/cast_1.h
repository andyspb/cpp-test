#ifndef _CAST_1_H_
#define _CAST_1_H_

#include <iostream>

namespace cast_1 {
class Base {
 public:
  Base()
      : i(1) {
    std::cout << "From Base::Base() " << std::endl;
  }
  int i;
};
class Derived : public Base {
 public:
  Derived()
      : ii(2),
        p(0) {
    std::cout << "From Derived::Derived()" << std::endl;
  }
  int ii;
  int * p;
};

int test() {
  std::cout << "Test: cast_1 --->" << std::endl;
  Base * base = new Base;
  Derived * derived_ptr = static_cast<Derived*>(base);

  if (derived_ptr) {
    std::cout << "derived_ptr->i=" << derived_ptr->i << std::endl;
    std::cout << "derived_ptr->ii=" << derived_ptr->ii << std::endl;
    std::cout << "derived_ptr->p=" << derived_ptr->p << std::endl;
  }
  return 1;
}
}  // namespace cast_1

#endif // _CAST_1_H_
