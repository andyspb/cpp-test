#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include <iostream>

namespace adapter {
class Adaptee {
  public:
    void methodB() {
      std::cout << "\tFrom Adaptee->methodB()\n";
    }
};

class Adapter {
  public:
    void methodA() {
      std::cout << "From Adapter->method()\n";
      adaptee.methodB();
    }
  private:
    Adaptee adaptee;
};

int test() {
  std::cout << "Test: Adapter pattern: --->" << std::endl;
  Adapter a;
  a.methodA();
  std::cout << "<-- test passed" << std::endl;
  return 1;
}

}  // namespace adapter

#endif // _ADAPTER_H_
