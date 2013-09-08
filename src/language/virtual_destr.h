#ifndef VIRTUAL_DESTR_H_
#define VIRTUAL_DESTR_H_

#include <iostream>
namespace virtual_destr {

class Base {
  public:
    Base() {
      std::cout <<  "From Base()" << std::endl;
    }
    ~Base() {
      std::cout <<  "From ~Base()" << std::endl;
    }
};

class Derived: public Base {
  public:
    Derived() {
      std::cout <<  "From Derived()" << std::endl;
    }
    ~Derived() {
      std::cout <<  "From ~Derived()" << std::endl;
    }
};

int test() {
  std::cout<<"Test: virtual destructors --->" << std::endl;
  std::cout<< "Base* b = new Derived();" <<std::endl;
  Base* b = new Derived();
  delete b;

  std::cout<< "Derived* d = new Derived();" <<std::endl;
  Derived* d = new Derived();
  delete d;

  return 1;
}
} // virtual_destr

#endif /* VIRTUAL_DESTR_H_ */
