#ifndef METHOD_HIDING_H_
#define METHOD_HIDING_H_

#include <iostream>

namespace method_hiding {

class Base {
 public:
  virtual ~Base() {
  }

  Base() {
    i = 1;
  }
  void f() {
    std::cout << "From Base::f() i=" << i << std::endl;
  }

  int i;
};

class Derived : public Base {
 public:
  virtual ~Derived() {
  }
  Derived() {
    i = 2;
  }
 public:
  void f() {
    std::cout << "From Derived::f() i=" << i << std::endl;
  }

  void f(int a) {
    std::cout << "From Derived::f(int) i=" << i << std::endl;
    std::cout << "Base::i=" << Base::i << std::endl;
  }

  void test() volatile {
  }

  int i;
};

void func(Base& b) {
  std::cout << "From func(Base& b)" << std::endl;
  b.f();
}

void func(Base& b, int a) {
  std::cout << "From func(Base& b, int a)" << std::endl;
  b.f();
  std::cout << "a=" << a << std::endl;
}

class FirstClass {
 public:
  virtual ~FirstClass() {
  }
  virtual void MethodA(int);
  virtual void MethodA(int, int);
};
void FirstClass::MethodA(int i) {
  std::cout << "ONE !!\n";
}
void FirstClass::MethodA(int i, int j) {
  std::cout << "TWO !!\n";
}

class SecondClass : public FirstClass {
 public:
  using FirstClass::MethodA;
  virtual ~SecondClass() {
  }
  ;
  void MethodA(int);
};
void SecondClass::MethodA(int i) {
  std::cout << "THREE!!\n";
}
int test() {
  Base * d = new Derived;
  d->f();
  delete d;

  SecondClass a;
  a.MethodA(1);
  a.MethodA(1, 1);
  return 1;
}

}  // namespace method_hiding

#endif /* METHOD_HIDING_H_ */
