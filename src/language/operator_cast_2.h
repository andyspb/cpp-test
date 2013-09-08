#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const char * s) {

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
  cout << "Test operator overloading" << endl;

  std::cout << "Hello !" << std::endl;

  cout << endl;
}
