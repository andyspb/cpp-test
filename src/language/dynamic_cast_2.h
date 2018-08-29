/*
 * dynamic_cast_2.h
 *
 *  Created on: 03 марта 2014 г.
 *      Author: andy
 */

#ifndef DYNAMIC_CAST_2_H_
#define DYNAMIC_CAST_2_H_

#include <iostream>

namespace dynamic_cast_2 {

struct A {
  virtual void f() {
    std::cout << "Class A" << std::endl;
  }
  virtual ~A() {
  }
  ;
};

struct B : A {
  virtual void f() {
    std::cout << "Class B" << std::endl;
  }
  virtual ~B() {
  }
  ;
};

struct C : A {
  virtual void f() {
    std::cout << "Class C" << std::endl;
  }
  virtual ~C() {
  }
  ;
};

void f(A* arg) {
  B* bp = dynamic_cast<B*>(arg);
  C* cp = dynamic_cast<C*>(arg);

  if (bp)
    bp->f();
  else if (cp)
    cp->f();
  else
    arg->f();
}
;

int test() {
  A aobj;
  C cobj;
  A* ap = &cobj;
  A* ap2 = &aobj;
  f(ap);
  f(ap2);
  return 1;
}

}  // namespace dynamic_cast_2

#endif /* DYNAMIC_CAST_2_H_ */
