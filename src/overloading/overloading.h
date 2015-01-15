/*
 * overloading.h
 *
 *  Created on: 15 џэт. 2015 у.
 *      Author: andy
 */

#ifndef OVERLOADING_H_
#define OVERLOADING_H_

#include <iostream>

namespace overloading {

struct X { };
void operator!(X) {
  std::cout << "void operator!(X)" << std::endl;
}

struct Y {
  void operator!() {
    std::cout << "void Y::operator!()" << std::endl;
  }
};


int test() {
  return 1;
}

}



#endif /* OVERLOADING_H_ */
