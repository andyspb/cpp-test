#ifndef FUNCTION_PARAMETER_H_
#define FUNCTION_PARAMETER_H_

#include <iostream>

namespace function_parameter {

void f(int i) {
  std::cout << "From f(int i)" << std::endl;
}
void f(char i) {
  std::cout << "From f(char i)" << std::endl;
}

void fp(int i) {
  std::cout << "From fp(int i)" << std::endl;
}

void fp(char* i) {
  std::cout << "From fp(char* i)" << std::endl;
}

int test() {
  char c = 'c';
  f(c);
  fp(&c);
  return 1;
}
}  // namespace function_parameter

#endif  // FUNCTION_PARAMETER_H_
