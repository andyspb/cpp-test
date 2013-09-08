#ifndef _INHERITANCE_LIST_H_
#define _INHERITANCE_LIST_H_

#include <iostream>
#include <memory>
#include <cstdlib>

namespace inheritance {

class A {
  public:
    void f() {
      std::cout << "from A::f()" << std::endl;
    }

};
class AA : public A {
};
class B: private AA {
  public:
    using A::f;
    void f(int) {
      std::cout << "from B::f()" << std::endl;
    }

};

class Base {
  public:
    Base() {

    }
};

class Derived : Base{
    Derived() {

    }
};

int test() {
  std::cout << "Different inheritance case: -->" << std::endl;
  std::auto_ptr<B> p(new B());
  p->f();
  std::cout << "<--" << std::endl;
  return 1;
}
}  // namespace inheritance

#endif  // _INHERITANCE_LIST_H_
