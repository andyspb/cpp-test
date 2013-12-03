#ifndef VIRT_FUNC_7_H
#define VIRT_FUNC_7_H

#include <stdio.h>

namespace virt_func_7 {

class A {
  public:
    virtual ~A() {}
    virtual void print() {printf("in A\n");}
};

class B: public A{
  public:
    virtual void print() {printf("in B\n");}
};

static void f(A a){
    a.print();
}

int test() {
    B b;
    f(b);
    return 1;
}

}  // end of virt_func_7
#endif // VIRT_FUNC_7_H
