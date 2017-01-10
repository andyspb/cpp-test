/*
 * test_2.h
 *
 *  Created on: 23 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_LEAP_TEST_2_H_
#define SRC_LEAP_TEST_2_H_

namespace _leap_2 {

class A {
 public:
//  virtual
  void f() {
    std::cout << "A";
  }
};

class B : public A {
 public:
//  virtual
  void f() {
    std::cout << "B";
  }
};

void g(A &a) {
  a.f();
}

TEST_RESULT test() {
  __SCOPE_LOG__;
//  A a;
  B b;
  g(b);

  RETURN_OK();

}

}  // namespace test_2

#endif /* SRC_LEAP_TEST_2_H_ */
