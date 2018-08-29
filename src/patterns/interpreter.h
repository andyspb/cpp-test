#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <iostream>
#include <string>

namespace interpreter {

class Interpreter {
 public:
  template<typename It>
  void run(It from, It to) {
    for (It i = from; i != to; ++i) {
      switch (*i) {
        case 'h':
          std::cout << "Hello";
          break;
        case ' ':
          std::cout << ' ';
          break;
        case 'w':
          std::cout << "world";
          break;
        case '!':
          std::cout << '!';
          break;
        case 'n':
          std::cout << std::endl;
          break;
        default:
//            throw std::runtime_error("Unknown command");
          break;
      }
    }
  }
};

void _hello_world(const std::string & script) {
  Interpreter().run(script.begin(), script.end());
}

int test() {
  std::cout << "Test: Interpreter pattern example --->" << std::endl;
  std::string str = "h w!n";
  std::cout << str << "\n";
  _hello_world(str);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace interpreter

#endif // _INTERPRETER_H_
