//  static_cast.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 20, 2012


#ifndef STATIC_CAST_H_
#define STATIC_CAST_H_

#include <iostream>

namespace static_cast_ {

class Base {
  public:
    virtual ~Base () {}
    void foo() {
      std::cout<<"from Base::foo()"<<std::endl;
    }
};

class Derived : public Base {
  public:
    Derived() : i(10) {}
    void foo() {
      std::cout<<"from Derived::foo()"<<std::endl;
    }
    int i;
};

int test() {
  std::cout << "Test static_cast --->" << std::endl;
  Base *b = new Base();
  b->foo();

  std::cout<< "sizeof b:" << sizeof(*b) << std::endl;

  Derived *d = static_cast<Derived *>(b);

  if (!d) {
    std::cout<<"d is NULL" << std::endl;
  } else {
    d->foo();
    std::cout<<"d.i " << d->i << std::endl;
    std::cout<< "sizeof d:" << sizeof(*d) << std::endl;
  }

  Derived *din = dynamic_cast<Derived *>(b);

  if (!din) {
    std::cout<<"din is NULL" << std::endl;
  } else {
    din->foo();
    std::cout<<"din.i " << din->i << std::endl;
    std::cout<< "sizeof d:" << sizeof(*din) << std::endl;
  }


  int *i1 = new int();
  void *v1  = static_cast<void*>(i1);
  int *ii1 = static_cast<int*>(v1);

  if ( i1 == ii1 ) {
    std::cout<< " i1 == ii1 " << i1 << std::endl;
  }

  int *i2 = new int();
  void *v2  = reinterpret_cast<void*>(i2);
  int *ii2 = reinterpret_cast<int*>(v2);

  if ( i2 == ii2 ) {
    std::cout<< " i2 == ii2 " << i2 << std::endl;
  }


  delete b;
  delete i1;
  delete i2;
  return 1;
}

}  // namespace static_cast_

#endif  // STATIC_CAST_H_
