#ifndef _CONST_METHOD_H_
#define _CONST_METHOD_H_

#include <iostream>

namespace const_method {

class Class {
  public:
    Class() {}
    void f() {
      std::cout << "From Class::f()" << std::endl;
    }

    void f_const() const {
      std::cout << "From Class::f_const() const" << std::endl;
      Class *c = (Class*)this;
      c->bar();
    }

    void bar() {
      std::cout << "From Class::bar()" << std::endl;
    }
};

int test() {
  std::cout << "Test: const method --->" << std::endl;
  Class c;
  const Class cc;

  c.f();
  c.f_const();

//  cc.f(); // error: cannot convert 'this' pointer from
            // 'const const_method::Class' to 'const_method::Class &'
  cc.f_const();

  c.bar();
  return 1;
}
}  // namespace const_method

#endif  // _CONST_METHOD_H_
