#ifndef _TEMPLATE_TEST2_H_
#define _TEMPLATE_TEST2_H_

#include <iostream>
#include <string>

namespace template_test2 {
template<int a[4]> struct _A {
};
//template<int f(int)> struct _B {
//};

int i;
int g(int) {
  return 0;
}

_A<&i> x;
//_B<&g> y;

typedef char mytype;

template<class T> class Key {
 public:
  Key()
      : kptr(NULL),
        length(0) {
    std::cout << __FUNCTION__ << std::endl;
  }

  Key(T)
      : kptr(NULL),
        length(0) {
    std::cout << __FUNCTION__ << std::endl;
  }

 private:
  T k;
  T* kptr;
  int length;
};

template<class T> class K {
 public:
  static T x;
};
template<class T> T K<T>::x;

template<class T> class A {
//        typename T::x(y);
  typedef char C;
  typename A::C d;
};

template<bool> class Assert;
template<> class Assert<true> {
};
Assert<4 == sizeof(int)> int_assert;

template<template<class T> class X> class tA {
};
template<class T> class tB {
};

tA<tB> a;

template<class T, class U = int> class dA;
template<class T = float, class U> class dA;
template<class T, class U> class dA {
 public:
  dA()
      : x(0),
        y(0) {
  }
  ;
  T x;
  U y;
};

template<unsigned> class IntSizeAssert;
template<> class IntSizeAssert<4> {
};

//IntSizeAssert<sizeof(int)> Assert;

namespace default_param {
template<class T, class U, class V = int> class X {
};
}

template<class T> void f() {
  std::cout << "<class T>f()" << std::endl;
}
;

template<int i> void f() {
  std::cout << "<int i>f()" << std::endl;
}
;

int test() {
  f<0>();

  K<int>::x = 0;
//		A<string> a;

  Key<std::string> key;
  Key<std::string> key_str("test");
  Key<int> i;
  Key<char*> c;
  Key<mytype> m;

  dA<> da;
  //da.x = 0;
  //da.y = 1;
  std::cout << da.x << " " << da.y << " " << std::endl;
  return 1;
}
}  // namespace template_test2

#endif  // _TEMPLATE_TEST2_H_
