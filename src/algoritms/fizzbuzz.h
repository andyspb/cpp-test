/*
 * fizzbuzz.h
 *
 *  Created on: 10 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_FIZZBUZZ_H_
#define SRC_ALGORITMS_FIZZBUZZ_H_

#include <iostream>

namespace fizzbuzz {

TEST_RESULT test() {
  __SCOPE_LOG__;
  for (int i = 1; i <= 100; ++i) {
    bool mul3 = (i % 3) == 0;
    bool mul5 = (i % 5) == 0;

    if (mul3 && mul5)
      std::cout << "FizzBuzz" << std::endl;
    else if (mul3)
      std::cout << "Fizz" << std::endl;
    else if (mul5)
      std::cout << "Buzz" << std::endl;
    else
      std::cout << i << std::endl;
  }

  RETURN_OK();
}

}  // namespace fizzbuzz

#endif /* SRC_ALGORITMS_FIZZBUZZ_H_ */
