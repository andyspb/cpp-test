/*
 * virtuals.h
 *
 *  Created on: Feb 27, 2014
 *      Author: andy
 */

#ifndef VIRTUAL_METHOD_2_H_
#define VIRTUAL_METHOD_2_H_

#include <iostream>

namespace virtual_method_2 {

struct A {
  /*virtual*/
  void f() {
    std::cout << "Class A" << std::endl;
  }
};

struct B : A {
  void f() {
    std::cout << "Class B" << std::endl;
  }
};

void g(A& arg) {
  arg.f();
}

int test() {
  B x;
  g(x);
  return 1;
}

}  // namespace virtuals

#endif  // VIRTUAL_METHOD_2_H_
