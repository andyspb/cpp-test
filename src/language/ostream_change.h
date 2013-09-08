#pragma once
#include <iostream>
#include <string>
namespace ostream_change {
using namespace std;

ostream& operator<<(ostream& out, const char* ch) {
  string str(ch);
  if (!strcmp(ch, "Andrey")) {
    str = "Boss";
  }
  out << str;
  return out;

}

void test() {

  cout << "Operator casting test\n" << "Hello " << "Andrey" << "\n";
}

}
