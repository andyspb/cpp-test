#ifndef TESTS4_H_
#define TESTS4_H_

#include <iostream>

namespace test_4 {

class A {
 public:
  virtual ~A() {
  }
  void hello() {
    std::cout << "hello()" << std::endl;
  }
  virtual void hello_1() {
    std::cout << "hello1()" << std::endl;
  }
};
// ...

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  A* a;
//  a->hello();

#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#pragma GCC diagnostic push
  a->hello_1();
#pragma GCC diagnostic pop

  RETURN_OK();
}

}

#endif  // TESTS4_H_
