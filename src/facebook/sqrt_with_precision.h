/*
 * sqrt_with_precision.h
 *
 *  Created on: 21 дек. 2013 г.
 *      Author: andy
 */

#ifndef SQRT_WITH_PRECISION_H_
#define SQRT_WITH_PRECISION_H_

#include <iostream>
#include <math.h>

namespace sqrt_with_precision {

// Newton's Approximation Method
double sqrt11(const double number) {
  const double epsilon = 0.000001;
  double lower, upper, guess;

  if (number < 1) {
    lower = number;
    upper = 1;
  } else {
    lower = 1;
    upper = number;
  }

  while ((upper - lower) > epsilon) {
    guess = (lower + upper) / 2;
    if (guess * guess > number)
      upper = guess;
    else
      lower = guess;
  }
  return (lower + upper) / 2;
}

double sqrt(double value) {
  double epsilon = 0.000001;
  if (value < 0) {
    return -1;
  }
  if (value == 0) {
    return 0;
  }
  double x(value);
  double last(0);
  for (; std::abs(last - x) > epsilon;
      /*int i = 0; (i < 1000) && (((x*x)+epsilon) >value); ++i*/) {
    last = x;
    x = (x + (value / x)) / 2;
  }
  return x;
}

int test() {
  std::cout << "Test sqrt_with_precision: --->\n";
  std::cout << "sqrt(22)= " << sqrt(22) << "\n";
  std::cout << "sqrt11(22)= " << sqrt11(22) << "\n";
  std::cout << "<--- end test\n";
  return 1;
}

}  // namespace sqrt_with_precision

#endif /* SQRT_WITH_PRECISION_H_ */
