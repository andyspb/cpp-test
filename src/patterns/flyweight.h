#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

#include <iostream>

namespace flyweight {

class Character {
  char ch;
 public:
  Character(char c)
      : ch(c) {
  }
  void output() const {
    std::cout << ch;
  }
};

struct OutputChar {
  void operator()(char ch) const {
    Character(ch).output();
  }
};

void hello_world(const std::string & message) {
  std::for_each(message.begin(), message.end(), OutputChar());
}

int test() {
  std::cout << "Test: Flyweight pattern example --->" << std::endl;
  hello_world("Hello world!\n");
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace flyweigtht

#endif // _FLYWEIGHT_H_
