/*
 * template_fibonacci.h
 *
 *  Created on: 05 џэт. 2015 у.
 *      Author: andy
 */

#ifndef TEMPLATE_FIBONACCI_H_
#define TEMPLATE_FIBONACCI_H_

namespace template_fibonacci {

template<int n>
struct Fibonacci {
  enum {
    value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value
  };
};

template<>
struct Fibonacci<2> {
  enum {
    value = 1
  };
};

template<>
struct Fibonacci<1> {
  enum {
    value = 1
  };
};

template<>
class Fibonacci<0> {
 public:
  enum {
    value = 0
  };
};

int test() {
  constexpr int c = 3;
  std::cout << "Fibonacci(10)=" << Fibonacci<c>::value << std::endl;

  return 1;
}

}  // namespace template_fibonacci

#endif /* TEMPLATE_FIBONACCI_H_ */
