#include <iostream>
using namespace std;
namespace virt_access {
class Base {
  public:
    virtual ~Base() {
    }
    virtual void f() {
      cout << __FUNCTION__ << endl;
    }
};

class Derived: public Base {
  public:
    virtual ~Derived() {
    }
  private:
    void f() {
      cout << __FUNCTION__ << endl;
    }
    ;
};

int test() {
  Derived dobj;
  Base* bptr = &dobj;
  // D* dptr = &dobj;

  // valid, virtual B::f() is public,
  // D::f() is called
  bptr->f();

  // error, D::f() is private
  //dptr->f();
  return 1;
}
}
