/*
 * cpp1x_constexpr_factorial.h
 *
 *  Created on: Jul 29, 2015
 *      Author: andy
 */

#ifndef SRC_CPP1X_CONSTEXPR_FACTORIAL_H_
#define SRC_CPP1X_CONSTEXPR_FACTORIAL_H_

#include <iostream>
#include <stdexcept>

namespace constexpr_factorial {

// The C++11 constexpr functions use recursion rather than iteration
// (C++14 constexpr functions may use local variables and loops)
constexpr int factorial(int n) {
  return n <= 1 ? 1 : (n * factorial(n - 1));
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  int f = factorial(5);
  LOG(INFO) << "factorial(5)=" << f;

  RETURN_OK();
}

}  // namespace cpp1x_constexpr_factorial

#endif /* SRC_CPP1X_CONSTEXPR_FACTORIAL_H_ */
