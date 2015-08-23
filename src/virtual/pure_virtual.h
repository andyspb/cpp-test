/*
 * pure_virtual.h
 *
 *  Created on: 21 рту. 2015 у.
 *      Author: andy
 */

#ifndef SRC_VIRTUAL_PURE_VIRTUAL_H_
#define SRC_VIRTUAL_PURE_VIRTUAL_H_

namespace pure_virtual {

class Base {
  int x;
 public:
  virtual void print()=0;
};

void Base::print() {
  std::cout << "Base x:"<< x << std::endl;
}

class Derived : public Base {
  int y;
 public:
  void print() {
    Base::print();
    std::cout <<"Derived y:"<< y << std::endl;
  }
};

TEST_RESULT test() {
  Derived d;
  d.print();
  Base* b = new Derived();
  b->print();

  RETURN_OK();
}

}  // namespace pure_virtual

#endif /* SRC_VIRTUAL_PURE_VIRTUAL_H_ */
