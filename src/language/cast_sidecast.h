/*
 * cast_sidecast.h
 *
 *  Created on: Sep 14, 2015
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_CAST_SIDECAST_H_
#define SRC_LANGUAGE_CAST_SIDECAST_H_

#include <iostream>

namespace cast_sidecast {

class A {
 public:
  virtual ~A() {
  }
};

class B {
 public:
  virtual ~B() {
  }
};

class Derived : public A, public B {
 public:
  virtual ~Derived() {
  }
};

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::cout << std::boolalpha;

  A *a = new Derived();
  B *b = dynamic_cast<B*>(a);
  std::cout << "b="<<b << "\n";

  RETURN_OK();
}

}  // namespace cast_sidecast

#endif /* SRC_LANGUAGE_CAST_SIDECAST_H_ */
