#pragma once
#include <iostream>

namespace embar {
struct A {
  virtual ~A() {
  }
  int value;
  virtual void doTest(int i = 1) {
    std::cout << "from A " << std::endl;
    value = i;
  }
};

struct B : public A {
  virtual ~B() {

  }
  virtual void doTest(int i = 999) {
    std::cout << "from B" << std::endl;
    value = i;
  }
};

void t1(char *a[]) {

}
void t2(char *a[2]) {

}

int test() {
  A * a = new B();
  a->doTest();
  cout << "value=" << a->value << endl;
  A a1;

  delete a;

  //int n = sizeof(VOID);
  return 1;
}
}  // namespace embar
