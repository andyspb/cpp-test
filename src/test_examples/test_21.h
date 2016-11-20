// tests21.h
// author: andrey.krutogolov@gmail.com
// date:   11.04.2013

#ifndef TESTS21_H_
#define TESTS21_H_

namespace test_21 {

struct A {
  A() {
    test(1);
  }

  virtual ~A() {
    test(2);
  }

  virtual void test(int i) {
    opps();
  }

  virtual void opps() = 0;
};

struct B : public A {
  B() {
    test(3);
  }

  ~B() {
    test(4);
  }

  void opps() {
  }
};
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  A* ptrA = new B;
  delete ptrA;
  RETURN_OK();
}

}  // namespace tests21

#endif  // TESTS21_H_
