// tests22.h
// author: andrey.krutogolov@gmail.com
// date:   14.04.2013

#ifndef TESTS22_H_
#define TESTS22_H_

//#include "logger.h"
namespace tests22 {

class Base {
 public:
  virtual void DoSome() {
  }

  virtual ~Base() {
  }
};

class Derived {
 public:
  virtual void DoSome() {
//    D:\cpp-test\src\tests/tests22.h:25:21: error: lvalue required as left operand of assignment
//    http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fcplr035.htm
    // this = new Base();
  }

  virtual ~Derived() {
  }
};

int main() {

//  LOG("Tests22");
  return 0;
}

}  // namespace tests22

#endif  // TESTS22_H_
