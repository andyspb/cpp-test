#pragma once
#include <iostream>
using namespace std;
namespace intialization_test
{

class A {
  public:
    A() {
    cout << "A\n";
    }
};
class B {
  public:
    B() {
    cout << "B\n";
    }
};
class C {
  public:
    C() {
    cout << "C\n";
    }
};
class D {
  public:
    D() {
    cout << "D\n";
    }
};
class E: virtual A, virtual B, virtual C {
  public:
    E() {
    cout << "E\n";
    }
};
class F: virtual D, virtual C {
  public:
    F() {
    cout << "F\n";
    }
};
class G: F, E {
  public:
    G() {
    cout << "G\n";
    }
};

void test()
{
  G g;
}

}
