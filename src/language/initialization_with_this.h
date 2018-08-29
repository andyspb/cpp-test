//  initialization_with_this.h
//  author: andrey.krutogolov@gmail.com
//  date:   Dec 6, 2012

#ifndef INITIALIZATION_WITH_THIS_H_
#define INITIALIZATION_WITH_THIS_H_

#include <iostream>

namespace intialization_with_this {

class Base {
 public:
  Base(Base* b)
      : base(b) {
  }
  virtual ~Base() {
  }
  virtual void print() {
    std::cout << "B::print()" << std::endl;
  }
  virtual void in_print() {
    if (base) {
      base->print();
    }
  }
 protected:
  Base* base;

};

class Derived : public Base {
 public:
  Derived()
      : Base(this) {
  }

  virtual ~Derived() {
  }
  virtual void print() {
    std::cout << "D::print()" << std::endl;
  }
};

int test() {
  std::cout << "Test initialisation list with this usage" << std::endl;
  Base* d = new Derived();
  Base* temp = dynamic_cast<Base*>(d);
  if (temp) {
    temp->in_print();
  }
  delete d;
  return 1;
}

}  // namespace intialization_with_this

#endif  // INITIALIZATION_WITH_THIS_H_
