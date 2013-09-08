#ifndef _DYNAMIC_CAST_H_
#define _DYNAMIC_CAST_H_

#include <iostream>

namespace dynamic_cast_ {

class Base {
  public:
    Base() {
      i = 1;
    }
    virtual ~Base() {
    }
    virtual void f() {
      std::cout << "from Base::f() " << std::endl;
    }
    int i;
};

class Derived: public Base {
  public:
    Derived() {
      i = 3;
      j = 2;
    }
    virtual ~Derived() {
    }
    virtual void f() {
      std::cout << "from Derived::f() " << std::endl;
    }
    int j;
};

class CBase {
  public:
    virtual ~CBase() {
    }
};
class CDerived: public CBase {
  public:
    ~CDerived() {
    }
};

int test() {
  std::cout << "dynamic_cast: " << std::endl;
  __attribute__((unused)) Base *b1 = new Base;
  std::cout << sizeof(Base) << std::endl;
//  if (dynamic_cast<Derived*>(b1) == NULL) {
//    std::cout << " FAILED dynamic_cast<Derived*>(b1)" << std::endl;
//  } else {
//    std::cout << " OK dynamic_cast<Derived*>(b1)" << std::endl;
//  }

  Base *b2 = new Derived;
  std::cout << sizeof(Derived) << std::endl;
  b2->f();
  std::cout << b2->i << std::endl;
  std::cout << typeid(b2).name() << std::endl;
  Derived *d = dynamic_cast<Derived*>(b2);
  if (d == NULL) {
    std::cout << " FAILED dynamic_cast<Derived*>(b2)" << std::endl;
  } else {
    std::cout << " OK dynamic_cast<Derived*>(b2)" << std::endl;
    b2->f();
    std::cout << d->j << std::endl;
  }

  CBase * a = new CBase;
  CDerived * b = static_cast<CDerived*>(a);
  if (b == NULL) {
    std::cout << " FAILED static_cast<CDerived*>(a)" << std::endl;
  } else {
    std::cout << " OK static_cast<CDerived*>(a)" << std::endl;
  }

  return 1;
}

}  // namespace dynamic_cast_

#endif
