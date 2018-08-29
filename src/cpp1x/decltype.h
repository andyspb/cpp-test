/*
 * decltype.h
 *
 *  Created on: 10 ���. 2016 �.
 *      Author: andy
 */

#ifndef SRC_CPP1X_DECLTYPE_H_
#define SRC_CPP1X_DECLTYPE_H_

#include <iostream>

namespace decltype_ {

struct A {
  double x;
  int i;
};

const A* a = new A { 0 };

int foo() {
  return 1;
}

decltype(a->x) y;       // type of y is double (declared type)
decltype(a->i) i_;       // type of y is int (declared type)
decltype((a->x)) z = y;  // type of z is const double& (lvalue expression)

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u);  // return type depends on template parameters

TEST_RESULT test() {
  __SCOPE_LOG__;

  int i = 33;
  decltype(i) j = i * 2;

  std::cout << "i = " << i << ", " << "j = " << j << '\n';

  auto f = [](int a, int b) -> int
  {
    return a * b;
  };

  decltype(f) g = f;  // the type of a lambda function is unique and unnamed
  i = f(2, 2);
  j = g(3, 3);

  std::cout << "i = " << i << ", " << "j = " << j << '\n';

  auto x = foo();                       // more concise than `decltype(foo()) x`

  RETURN_OK();
}

}  // namespace decltype_

#endif /* SRC_CPP1X_DECLTYPE_H_ */
