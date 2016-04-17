#ifndef _GOOGLE_TEST_H_
#define _GOOGLE_TEST_H_

// google test
#include <algorithm>
#include <complex>
#include <iostream>
#include <stdio.h>

namespace google_test {
class A {
 public:
  A() {
    std::cout << "From ctor A::A() " << std::endl;
  }
 protected:
  virtual ~A() {
    std::cout << "From A::~A() " << std::endl;
  }
};

class B : public A {
 public:
  B() {
    std::cout << "From ctor B::B() " << std::endl;
  }
  ~B() {
    std::cout << "From B::~B() " << std::endl;
  }
};

int test() {
  B* b = new B();
  delete b;
//  A * a1 = new B();
//  delete a1;
//  A * a = new A();
//  delete a;
  return 1;
}
//
//0  1  2  3  4  5  6  7
//8  9  10 11 12 13 14 15
//16 17 18 19 20 21 22 23
//24 25 26 27 28 29 30 31
//...
//56 57 58 59 60 61 62 63
int minNumMoves(int start, int target) {
  if (start == target)
    return 0;
  int x = start % 8;
  int y = start / 8;
  int tx = target % 8;
  int ty = target / 8;
  if (((x + tx) % 2 == 1 && (y + ty) % 2 == 0)
      || ((x + tx) % 2 == 0 && (y + ty) % 2 == 1)) {
    return -1;
  }
  int a = (abs(target - start)) % 9;
  if (!a || 7 == a) {
    return 1;
  } else {
    return 2;
  }
}
}  // namespace google_test

#endif  // _GOOGLE_TEST_H_
