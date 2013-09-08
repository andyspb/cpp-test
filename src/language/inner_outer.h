#pragma once
#include <iostream>
#include <stdlib.h>
namespace inner_outer_test {
using namespace std;
class OuterClass {
  public:
    void outerFunction();

    class InnerClass {
      public:
        void innerFunction(OuterClass& outer);
    };

  private:
    /*static*/
    int i;
};
void OuterClass::outerFunction() {
  cout << "This is a function in the base class\n";
  InnerClass myclass;
  myclass.innerFunction(*this);
}
void OuterClass::InnerClass::innerFunction(OuterClass& outer) {
  cout << "This is a function in the InnerClass class \n";
  outer.i = 10;
}
void test() {
  OuterClass myclass;
  myclass.outerFunction();
}

//    int OuterClass::i=0;
}

