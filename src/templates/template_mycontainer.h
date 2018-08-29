#ifndef _TEMPLATE_MY_CONTAINER_H_
#define _TEMPLATE_MY_CONTAINER_H_

// template specialization
#include <iostream>

namespace template_mycontainer {

// class template:
template<class T>
class mycontainer {
  T element;
 public:
  mycontainer(T arg) {
    element = arg;
  }
  T increase() {
    return ++element;
  }
};

// class template specialization:
template<>
class mycontainer<char> {
  char element;
 public:
  mycontainer(char arg) {
    element = arg;
  }
  char uppercase() {
    if ((element >= 'a') && (element <= 'z'))
      element += 'A' - 'a';
    return element;
  }
};

int test() {
  std::cout << "Test: template mycontainer --->" << std::endl;
  mycontainer<int> myint(7);
  mycontainer<char> mychar('j');
  std::cout << myint.increase() << std::endl;
  std::cout << mychar.uppercase() << std::endl;
  std::cout << "<--- test passed " << std::endl;
  return 1;
}
}  // namespace template_mycontainer

#endif // _TEMPLATE_MY_CONTAINER_H_
