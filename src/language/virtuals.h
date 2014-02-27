/*
 * virtuals.h
 *
 *  Created on: Feb 27, 2014
 *      Author: andy
 */

#ifndef VIRTUALS_H_
#define VIRTUALS_H_


#include <iostream>
using namespace std;

namespace virtuals {

struct A {
  /*virtual*/  void f() { cout << "Class A" << endl; }
};

struct B: A {
   void f() { cout << "Class B" << endl; }
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



#endif /* VIRTUALS_H_ */
