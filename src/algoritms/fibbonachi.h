#ifndef _FIBBONACHI_H_
#define _FIBBONACHI_H_

#include <iostream>

namespace fibbonachi {
int fib(int n) {
  return (n <= 2 ? 1 : fib(n - 1) + fib(n - 2));
}

template<int n>
struct TFib {
    enum {
      value = TFib<n - 1>::value + TFib<n - 2>::value
    };
};

template<>
struct TFib<2> {
    enum {
      value = 1
    };
};

template<>
struct TFib<1> {
    enum {
      value = 1
    };
};

template<>
class TFib<0> {
  public:
    enum {
      value = 0
    };
};

int test() {
  std::cout << "Test: Fibbonachi" << std::endl;
  int N = 10;
  std::cout << "Recursion: ";
  for (int n = 1; n <= N; n++) {
    std::cout << fib(n) << ", ";
  }
  std::endl(std::cout);
  const int c = 10;
  std::cout << "Fibonnachi(10)=" << TFib<c>::value;
  std::endl(std::cout);
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  //namespace fibbonachi

#endif // _FIBBONACHI_H_
