#ifndef VIRT_TEST_5_H_
#define VIRT_TEST_5_H_

#include <iostream>
using namespace std;
namespace virt_func_5 {
struct A {
   virtual ~A() {}
   virtual void f() { cout << "Class A" << endl; }
};

struct B: A {
   virtual ~B() {}
   void f() { cout << "Class B" << endl; }
};

void g(A& arg) {
   arg.f();
}
int test() {
  std::cout << "Test: virtual function 5" << std::endl;
  B x;
  g(x);
  return 1;
}
} // namespace virt_func_5

#endif /* VIRT_TEST_5_H_ */
