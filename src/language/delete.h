#ifndef _DELETE_H_
#define _DELETE_H_

#include <iostream>

namespace delete_ {
  
class A {
public:
  void f() {
    delete this;
  }
};

int test() {
  A * a= new A();
//  delete &a;
  a->f();

  A a1;
  a1.f();
  return 1;
}

}  // namespace delete_ 

#endif // _DELETE_H_
