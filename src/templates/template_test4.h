#ifndef _TEMPLATE_TEST4_H_
#define _TEMPLATE_TEST4_H_

#include <iostream>

namespace template_test4 {
void f(double) {
  std::cout << "\tcalling f(double)" << std::endl;
}

// forward declaration
void h(int);

template<class T> void g(T a) {
  f(123);
  h(a);
}

void f(int) {
  std::cout << "\tcalling f(int)" << std::endl;
}

void h(double) {
  std::cout << "\tcalling h(double)" << std::endl;
}

void i() {
  extern void h(int);
  g<int>(234);
}

void h(int) {
  cout << "\tcalling h(int)" << endl;
}

int test() {
  std::cout << "Test: template2 --->" << std::endl;
  i();
  std::cout << "<--- template2 test passed" << std::endl;
  return 1;
}
}  // namespace templ_test2

#endif  // _TEMPLATE_TEST4_H_
