#include "stdafx.h"
namespace exception_test {
class Inner {
 public:
  Inner() {
    printf("ctor Inner\n");
  }
  ~Inner() {
    printf("destructor Inner\n");
  }
};

class A {
 public:
  A();
  ~A();
 private:
  int * p;
  Inner * in;
};

A::A() {
  printf("Constructor A\n");
  in = new Inner();
  p = new int;
  //	std::exception a("My exception from ctor\n");
  //throw a;
}

A::~A() {
  printf("Destructor A\n");
  //	std::exception a("My exception from destructor\n");
  //	throw a;
  delete in;
  delete p;
}

int test1() {
  try {
    A a;
  } catch (std::exception &e) {
    printf("%s", e.what());
  }
  return 0;
}

int test() {
  printf("%s %s exception test\n", __FILE__, __FUNCTION__);
  test1();
  printf("return\n");
  return 0;
}
}
