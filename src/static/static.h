/*
 * static.h
 *
 *  Created on: Nov 14, 2014
 *      Author: andy
 */

#ifndef STATIC_H_
#define STATIC_H_

#include <iostream>

class A {

 public:
  void print() {
    static int i = 0;
    ++i;
    std::cout << "i = " << i << std::endl;
  }
};

void print() {
  static int j = 0;
  ++j;
  std::cout << "j = " << j << std::endl;
}

namespace static_ {

int test() {
  A a;
  a.print();
  a.print();
  a.print();
  a.print();

  print();
  print();
  print();
  print();

  return 1;
}

}  // namespace static_

#endif /* STATIC_H_ */
