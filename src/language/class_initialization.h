#ifndef _CLASS_INITIALIZATION_H_
#define _CLASS_INITIALIZATION_H_

#include <iostream>

namespace class_initialization {
struct Struct {
    int a;
    int b;
};

class Class{
  public:
    int a;
    int b;
};

int test() {
  std::cout << "Test: class initialization --->" << std::endl;
  Struct s = { 'a', 2 };
  std::cout << "s.a="<< s.a << " s.b=" << s.b << std::endl;
  Class c = { 3, 4 };
  std::cout << "c.a="<< c.a << " c.b=" << c.b << std::endl;
  return 1;
}
} // namespace class_initialization

#endif // _CLASS_INITIALIZATION_H_
