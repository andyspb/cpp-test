#include <iostream>
template<class T>
bool ansisupported(T x) {
  return true;
}

int ansisupported_test() {
  if (ansisupported(0))
    std::cout << "ANSI OK" << std::endl;
  return 0;
}
