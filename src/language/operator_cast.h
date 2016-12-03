#pragma once

#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& out, const char * s) {
  std::string str(s);
  if (0 == strcmp(s, "Andrey")) {
    str = "andrey krutogolov";
    out << str;
  } else
    out << str;

  return out;

}

void operator_cast() {
  std::cout << "Operator casting test\n" << "Hello !\n" << "Andrey" << "\n";
}
