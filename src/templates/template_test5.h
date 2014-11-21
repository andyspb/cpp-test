/*
 * template_test5.h
 *
 *  Created on: Feb 27, 2014
 *      Author: andy
 */

#ifndef TEMPLATE_TEST5_H_
#define TEMPLATE_TEST5_H_

namespace template_test5 {

template<class T, class U = int> class A;
template<class T = float, class U> class A;

template<class T, class U> class A {
   public:
      T x;
      U y;
};

template<class T = char> class X;
template<class T> class X { };

template<class T = int> class A1;
template<class T = float> class B1;
template<class V, V obj> class C1;
// a template parameter (T) used as the default argument
// to another template parameter (U)
template<class T, class U = T> class D { };

template<class T> void f() { };
template<int i> void f() { };

template<class T, int size> class Myfilebuf
{
      T* filepos;
      static int array[size];
public:
      Myfilebuf(): T(0) { /* ... */ }
      ~Myfilebuf();
  //    advance(); // function defined elsewhere in program
};

int test() {
  A<> a;
  X<> x;

  f<int()>();
  return 1;
}

}  // template_test5

#endif /* TEMPLATE_TEST5_H_ */
