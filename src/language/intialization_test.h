#pragma once
#include <iostream>
namespace intialization_test {

class A {
 public:
  A() {
    std::cout << "A\n";
  }
};
class B {
 public:
  B() {
    std::cout << "B\n";
  }
};
class C {
 public:
  C() {
    std::cout << "C\n";
  }
};
class D {
 public:
  D() {
    std::cout << "D\n";
  }
};
class E : virtual A, virtual B, virtual C {
 public:
  E() {
    std::cout << "E\n";
  }
};
class F : virtual D, virtual C {
 public:
  F() {
    std::cout << "F\n";
  }
};
class G : F, E {
 public:
  G() {
    std::cout << "G\n";
  }
};

void test() {
  G g;
}
}
