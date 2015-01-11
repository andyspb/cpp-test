/*
 * inheritance.h
 *
 *  Created on: 31 дек. 2014 г.
 *      Author: andy
 */

#ifndef INHERITANCE_H_
#define INHERITANCE_H_

#include <iostream>

namespace inheritance_ {

class Base {
 public:
  Base(int v)
      : value(v) {};
  Base()
      : value(0) {};
  virtual ~Base() {};
  void setValue(int v) {
    value = v;
  }
 protected:
  virtual int getValue() {
    return value;
  }
  virtual void print() {
    std::cout << "From Base value="<< value << std::endl;
  }
 private:
  int value;
};

class Derived : private Base {
 public:
  Derived(int v) : Base(v) {}
  void print() {
    Base::print();
    std::cout << "From Derived value="<< Base::getValue() << std::endl; // error when value is private
    //   std::cout << "From Derived value="<< value << std::endl; // error when value is private
  }

  virtual void setValue(int v) {
    Base::setValue(v);
  }

};

int test() {
  std::cout << "Inheritance tests" << std::endl;
 // Base * b = new Derived(1); //error: 'inheritance_::Base' is an inaccessible base of 'inheritance_::Derived'
  Derived * d = new Derived(1);

  d->print();
  d->setValue(2);
  d->print();
//  delete b;
  delete d;
  return 1;
}

}  // inheritance_

#endif /* INHERITANCE_H_ */
