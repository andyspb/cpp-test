#pragma once
#include <iostream>
#include <string>
namespace ostream_change {

std::ostream& operator<<(std::ostream& out, const char* ch) {
  std::string str(ch);
  if (!strcmp(ch, "Andrey")) {
    str = "Boss";
  }
  out << str;
  return out;

}

void test() {
  std::cout << "Operator casting test\n" << "Hello " << "Andrey" << "\n";
}

}
