#ifndef PRIVATE_CONSTRUCTOR_H_
#define PRIVATE_CONSTRUCTOR_H_

#include <iostream>

namespace private_constructor {

class Class {
 private:
  Class() {
  }
 public:
  int value;
};

int test() {
  std::cout << "Test: create class with private constructor --->" << std::endl;
  Class c = c;
  std::cout << "c.value = " << c.value << std::endl;
  return 1;
}
}  // namespace private_constructor

#endif  // PRIVATE_CONSTRUCTOR_H_ 
