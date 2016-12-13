/*
 * dynamic_cast_3.h
 *
 *  Created on: 03 марта 2014 г.
 *      Author: andy
 */

#ifndef DYNAMIC_CAST_3_H_
#define DYNAMIC_CAST_3_H_

#include <iostream>
#include <exception>

namespace dynamic_cast_3 {

struct Base {
  virtual ~Base() {
  }
};
struct Derived : public Base {
  int a;
};

int test() {
  try {
    Base * pba = new Derived;
    std::cout << "pba == " << pba << std::endl;

    Base * pbb = new Base;
    std::cout << "pbb == " << pbb << std::endl;

    //    Base * pb;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    std::cout << "pd == " << pd << std::endl;
    if (pd == 0) {
      std::cout << "Null pointer on first type-cast" << std::endl;
    }

    pba = dynamic_cast<Derived*>(pba);
    std::cout << "pba == " << pba << std::endl;
    pd = dynamic_cast<Derived*>(pbb);
    std::cout << "pd == " << pd << std::endl;
    if (pd == 0) {
      std::cout << "Null pointer on second type-cast." << std::endl;
    }

    pbb = dynamic_cast<Derived*>(pba);
    std::cout << "pbb == " << pbb << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what();
  }
  return 1;
}

}  // namespace dynamic_cast_3

#endif /* DYNAMIC_CAST_3_H_ */
