/*
 * turn_off_ bit_in_number.h
 *
 *  Created on: 25 џэт. 2015 у.
 *      Author: andy
 */

#ifndef TURN_OFF__BIT_IN_NUMBER_H_
#define TURN_OFF__BIT_IN_NUMBER_H_

#include <iostream>

namespace turn_off_bit_in_number {

// Returns a number that has all bits same as n
// except the k'th bit which is made 0
int turnOffK(int n, int k) {
  // k must be greater than 0
  if (k <= 0)
    return n;

  // Do & of n with a number with all set bits except
  // the k'th bit
  return (n & ~(1 << (k - 1)));
}

// Driver program to test above function
int test() {
  int n = 15;
  int k = 4;
  std::cout << turnOffK(n, k);
  std::cout<<"\n";
  return 1;
}

}  // namespace turn_off_ bit_in_number

#endif /* TURN_OFF__BIT_IN_NUMBER_H_ */
