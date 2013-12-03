#ifndef VIRT_FUNC_8_H
#define VIRT_FUNC_8_H

#include <stdio.h>

namespace virt_func_8 {

class A {
public:
    virtual ~A() {}
    void print() {printf("in A\n");}
};

class B : public A{
public:
    virtual void print() {printf("in B\n");}
};

class C : public A{
public:
    virtual void print() {printf("in C\n");}
};

class D : public C{
public:
};


int test() {
    printf("virt_func_8::test()\n");
    A* a = new D;
    C* c = new D;
    a->print();
    c->print();

    delete a;
    delete c;

    return 1;
}

}  // namespace virt_func_8

#endif // VIRT_FUNC_8_H
