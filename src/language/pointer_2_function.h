#ifndef POINTER_2_FUNCTION_H_
#define POINTER_2_FUNCTION_H_

#include <iostream>

namespace pointer_to_function {

void f() {}

class Class {
  public:
    void f() {}
  private:
    void g() {}
};

typedef void (*func)();
typedef void (Class::*class_func)();

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  Class c;
  func  f1 = &f;
  f1();
  class_func f2 = &Class::f;
  (c.*f2)();
//  class_func f3 = &c.g();
  RETURN_OK();
}

} // namespace pointer_to_function

#endif /* POINTER_2_FUNCTION_H_ */
