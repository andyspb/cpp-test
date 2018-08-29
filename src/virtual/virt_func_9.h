#ifndef VIRT_FUNC_9_H
#define VIRT_FUNC_9_H

#include <stdio.h>

namespace virt_func_9 {

class A {
 public:
  A() {
    printf("A\n");
  }
  virtual ~A() {
    printf("~A\n");
  }
  virtual void print() {
    printf("in A\n");
  }
};

class B : /*virtual*/public A {
 public:
  B() {
    printf("B\n");
  }
};

class C : virtual public A {
 public:
  C() {
    printf("C\n");
  }
  virtual void print() {
    printf("in C\n");
  }
};

class D : public C, public B {
 public:
  D() {
    printf("D\n");
  }
};

int test() {
  printf("virt_func_9::test()\n");
  D* d = new D;
  // d->print();
  return 1;
}

}  // virt_func_9

#endif // VIRT_FUNC_9_H
