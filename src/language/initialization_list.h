#ifndef _INITIALIZATION_LIST_H_
#define _INITIALIZATION_LIST_H_

#include <iostream>
namespace intialization_list {

class VirtualBase {
 public:
  VirtualBase() {
    std::cout << "from VirtualBase::VirtualBase()" << std::endl;
  }
  virtual ~VirtualBase() {
    std::cout << "from VirtualBase::~VirtualBase()" << std::endl;
  }
  virtual void test() {
    std::cout << "from VirtualBase::test()" << std::endl;
  }
};

class BaseA {
 public:
  BaseA() {
    std::cout << "from BaseA::BaseA()" << std::endl;
  }
  virtual ~BaseA() {
    std::cout << "from BaseA::~BaseA()" << std::endl;
  }
};

class BaseB {
 protected:
  BaseB() {
    std::cout << "from BaseB::BaseB()" << std::endl;
  }
  virtual ~BaseB() {
    std::cout << "from BaseB::~BaseB()" << std::endl;
  }
};
class DerivedA : public BaseA, virtual public VirtualBase {
 public:
  DerivedA() {
    std::cout << "from DerivedA::DerivedA()" << std::endl;
  }
  virtual ~DerivedA() {
    std::cout << "from DerivedA::~DerivedA()" << std::endl;
  }
};
class DerivedB : public BaseB, virtual public VirtualBase {
 public:
  DerivedB() {
    std::cout << "from DerivedB::DerivedB()" << std::endl;
  }
  virtual ~DerivedB() {
    std::cout << "from DerivedB::!DerivedB()" << std::endl;
  }
};
class DerivedC : public DerivedA, public DerivedB {
 public:
  DerivedC() {
    std::cout << "from DerivedC::DerivedC()" << std::endl;
  }
  virtual ~DerivedC() {
    std::cout << "from DerivedC::~DerivedC()" << std::endl;
  }
};

int test() {
  std::cout << "Test: initialization list --->" << std::cout;
  DerivedC c;
  c.test();
  return 1;
}
}  // namespace intialization_list

#endif // _INITIALIZATION_LIST_H_
