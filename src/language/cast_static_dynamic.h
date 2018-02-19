/*
 * cast_static_dynamic.h
 *
 *  Created on: Jan 29, 2018
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_CAST_STATIC_DYNAMIC_H_
#define SRC_LANGUAGE_CAST_STATIC_DYNAMIC_H_

#include <iostream>

namespace cast_static_dynamic {

struct A {
  A()
      : a(0),
        b(0) {
  }

  virtual ~A() {
  }

  int a;
  int b;
};
struct B : A {
  B()
      : g(0) {
  }

  virtual ~B() {
  }

  int g;
};
struct D {
  D()
      : f(0) {
  }

  virtual ~D() {

  }

  float f;
};
struct C : A, D {
  C()
      : d(0) {
  }
  double d;
};

TEST_RESULT test_0() {
  C* c = new C;
  A* a = c;
  D* d = static_cast<D*>(c);
  std::cout << c << " " << d << " " << a << std::endl;

  RETURN_OK();
}
TEST_RESULT test_1() {
  C* pC = new C;
  A* pA = static_cast<A*>(pC);
  D* pD = static_cast<D*>(pC);
  B* pB = static_cast<B*>(pA);
  std::cout << &(pB->g) << " " << pD << " " << pA << std::endl;
  pB->g = 100;
  std::cout << pC->a << " " << pC->b << " " << pC->f << std::endl;
  return 0;
}

TEST_RESULT test_2() {
  C* c = new C;
  A* a = c;
  if (D* d = dynamic_cast<D*>(c))
    std::cout << " OK " << std::endl;
  else
    std::cout << " not OK " << std::endl;

  if (B* b = dynamic_cast<B*>(a))
    std::cout << " OK " << std::endl;
  else
    std::cout << " not OK " << std::endl;
  RETURN_OK();
}

TEST_RESULT test() {
  RETURN_OK();
}

}  // namespace cast_static_dynamic

#endif /* SRC_LANGUAGE_CAST_STATIC_DYNAMIC_H_ */
