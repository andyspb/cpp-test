#ifndef _SIZEOF_CLASS_H_
#define _SIZEOF_CLASS_H_

#include <iostream>

namespace test_sizeof {
class Base {
 public:
  virtual ~Base() {
  }
  virtual void function() {
  }
  virtual void function1() {
  }
  virtual void function2() {
  }
};

class Derived: public Base {
 public:
  virtual ~Derived() {
  }
  virtual void function() {
  }
  virtual void function1() {
  }
  virtual void function2() {
  }
};

class BaseClass {
  int a;
  char c;
};

class DerivedClass: public BaseClass {
  char d;
  int i;
};

class ABase {
  int iMem;
};

class BBase: public virtual ABase {
  int iMem;
};

class CBase: public virtual ABase {
  int iMem;
};

class ABCDerived: public BBase, public CBase {
  int iMem;
};
void test() {
  Derived a;
  std::cout << "size of a=" << sizeof(a) << std::endl;
  DerivedClass dc;
  std::cout << "size of dc=" << sizeof(dc) << std::endl;

  ABase ab;
  std::cout << "size of ab=" << sizeof(ab) << std::endl;
  BBase bb;
  std::cout << "size of bb=" << sizeof(bb) << std::endl;
  CBase cb;
  std::cout << "size of cb=" << sizeof(cb) << std::endl;
  ABCDerived abcd;
  std::cout << "size of abcd=" << sizeof(abcd) << std::endl;
  //abcd.test();
}
}  // namespace test_sizeof
