/*
 * test_24.h
 *
 *  Created on: Apr 25, 2016
 *      Author: andy
 */

#ifndef SRC_TESTS_TEST_24_H_
#define SRC_TESTS_TEST_24_H_

namespace test_24 {

struct A {
  A() {
    test(1);
  }

  virtual ~A() {
    test(2);
  }

  virtual void test(int i) {
    std::cout << i << ". A::test()\n";
  }
};

struct B : public A {
  B() {
    test(3);
  }

  ~B() {
    test(4);
  }

  void test(int i) {
    std::cout << i << ". B::test()\n";
  }
};
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  A* ptrA = new B;
  delete ptrA;
  RETURN_OK();
}

}  // namespace test_24

#endif /* SRC_TESTS_TEST_24_H_ */
