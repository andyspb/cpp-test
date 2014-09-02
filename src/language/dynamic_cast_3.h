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
using namespace std;

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
    cout << "pba == " << pba << ".\n";

    Base * pbb = new Base;
    cout << "pbb == " << pbb << ".\n";

    //    Base * pb;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    cout << "pd == " << pd << ".\n";
    if (pd == 0) {
      cout << "Null pointer on first type-cast.\n";
    }

    pba = dynamic_cast<Derived*>(pba);
    cout << "pba == " << pba << ".\n";


    pd = dynamic_cast<Derived*>(pbb);
    cout << "pd == " << pd << ".\n";
    if (pd == 0) {
      cout << "Null pointer on second type-cast.\n";
    }


    pbb = dynamic_cast<Derived*>(pba);
    cout << "pbb == " << pbb << ".\n";


  } catch (exception& e) {
    cout << "Exception: " << e.what();
  }
  return 1;
}

}  // namespace dynamic_cast_3

#endif /* DYNAMIC_CAST_3_H_ */
