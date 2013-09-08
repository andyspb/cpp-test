#pragma once

#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& out, const char * s) {
  string str(s);
  if (0 == strcmp(s, "Andrey")) {
    str = "andrey krutogolov";
    out << str;
  } else
    out << str;

  return out;

}

void operator_cast() {
  cout << "Operator casting test\n" << "Hello !\n" << "Andrey" << "\n";
}
