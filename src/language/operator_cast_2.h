#include <iostream>

std::ostream& operator<<(std::ostream& out, const char * s) {

  std::string str(s);
  if (0 == strcmp(s, "Hello !")) {
    str = "Hello Boss!";
    out << str;

  } else {
    out << str;
  }
  return out;
}

void OperatorCastingTest(void) {
  std::cout << "Test operator overloading" << std::endl;

  std::cout << "Hello !" << std::endl;

  std::cout << std::endl;
}
