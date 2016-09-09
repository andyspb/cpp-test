#ifndef _CLASS_INITIALIZATION_H_
#define _CLASS_INITIALIZATION_H_

#include <iostream>

namespace class_initialization {
struct Struct {
    int a;
    int b;
};

class Class{
  public:
    int a;
    int b;
};

TEST_RESULT test() {
  __SCOPE_LOG__;
  Struct s = { 'a', 2 };
  LOG(INFO) << "s.a="<< s.a << " s.b=" << s.b;
  Class c = { 3, 4 };
  LOG(INFO) << "c.a="<< c.a << " c.b=" << c.b;
  RETURN_OK();
}
} // namespace class_initialization

#endif // _CLASS_INITIALIZATION_H_
