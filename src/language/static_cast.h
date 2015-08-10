//  static_cast.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 20, 2012

#ifndef STATIC_CAST_H_
#define STATIC_CAST_H_

#include <iostream>

namespace static_cast_ {

class Base {
 public:
  virtual ~Base() {
  }
  void foo() {
    std::cout << "from Base::foo()" << std::endl;
  }
};

class Derived : public Base {
 public:
  Derived()
      : i(10) {
  }
  void foo() {
    std::cout << "from Derived::foo()" << std::endl;
  }
  int i;
};

struct Base_ {
};
//struct Derived_ : public virtual Base_ {}; // compile error
struct Derived_ : public Base_ {
};

void f() {
  Base_* b = new Derived_;
  Derived_* d = static_cast<Derived_*>(b);
}

class A
{
  public:
    virtual ~A() = 0;
};

inline A::~A() = default;

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  Base *b = new Base();
  b->foo();

  LOG(INFO) << "sizeof b:" << sizeof(*b);

  Derived *d = static_cast<Derived *>(b);

  if (!d) {
    LOG(INFO) << "d is NULL";
  } else {
    d->foo();
    LOG(INFO) << "d.i " << d->i;
    LOG(INFO) << "sizeof d:" << sizeof(*d);
  }

  Derived *d2 = dynamic_cast<Derived *>(b);

  if (!d2) {
    LOG(INFO) << "d2 is NULL";
  } else {
    d2->foo();
    LOG(INFO) << "din.i " << d2->i;
    LOG(INFO) << "sizeof d:" << sizeof(*d2);
  }

  int *i1 = new int();
  void *v1 = static_cast<void*>(i1);
  int *ii1 = static_cast<int*>(v1);

  if (i1 == ii1) {
    LOG(INFO) << " i1 == ii1 " << i1 ;
  }

  int *i2 = new int();
  void *v2 = reinterpret_cast<void*>(i2);
  int *ii2 = reinterpret_cast<int*>(v2);

  if (i2 == ii2) {
    LOG(INFO) << " i2 == ii2 " << i2 ;
  }

  delete b;
  delete i1;
  delete i2;
  RETURN_OK();
}

}  // namespace static_cast_

#endif  // STATIC_CAST_H_
