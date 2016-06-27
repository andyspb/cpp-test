/*
 * test_6.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_6_H_
#define SRC_TERAMIND_TERRAMIND_6_H_

namespace terramind_6 {

// Write a recursive function in C or C++ to calculate the Nth number
// in the Fibonacci sequence. *
unsigned long long fib(int n) {
  if (n == 1)
    return 0ULL;
  else if (n == 2)
    return 1ULL;
  else
    return fib(n - 1) + fib(n - 2);
}
// Fibonacci sequence. *

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}


}  // namespace test_6




#endif /* SRC_TERAMIND_TERRAMIND_6_H_ */
