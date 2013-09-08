// tests16.h
// author: andrey.krutogolov@gmail.com
// date:   01.04.2013


#ifndef TESTS16_H_
#define TESTS16_H_

#include <iostream>
using namespace std;


namespace tests16 {

class B;

class A {
 friend class B;
 public:
  A() {
    std::cout << "A::A()\n";
  }
  virtual ~A() {
    std::cout << "A::~A()\n";
  }
};

class B : A {
 public:
  B() {
    std::cout << "B::B()\n";
  }
  virtual ~B() {
    std::cout << "B::~B()\n";
  }
};

int main() {
 // A* a = new B();
//  delete a;
  return 1;
}

}  // namespace tests16

#endif  // TESTS16_H_
