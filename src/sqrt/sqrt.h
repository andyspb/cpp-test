/*
 * sqrt.h
 *
 *  Created on: 30 ����. 2014 �.
 *      Author: andy
 */

#ifndef SQRT_H_
#define SQRT_H_

#include <iostream>
#include "../logger/logger.h"

namespace sqrt_ {

float SquareRoot(float num) {
  if (num >= 0) {
    float x = num;
    int i;
    for (i = 0; i < 20; i++) {
      x = (((x * x) + num) / (2 * x));
    }
    return x;
  }

  return -1;
}

int test() {
  LOG(INFO) << __PRETTY_FUNCTION__ << " Test sqrt";
  std::cout << "SquareRoot(4) " << SquareRoot(4) << std::endl;
  std::cout << "SquareRoot(9) " << SquareRoot(9) << std::endl;
  std::cout << "SquareRoot(25) " << SquareRoot(25) << std::endl;
  std::cout << "SquareRoot(1024) " << SquareRoot(1024) << std::endl;
  return 1;
}

}  // namespace sqrt_

#endif /* SQRT_H_ */
