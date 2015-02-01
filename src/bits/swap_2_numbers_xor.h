/*
 * swap_2_numbers_xor.h
 *
 *  Created on: 01 февр. 2015 г.
 *      Author: andy
 */

#ifndef SWAP_2_NUMBERS_XOR_H_
#define SWAP_2_NUMBERS_XOR_H_

#include <stdio.h>

namespace swap_2_numbers_xor {

void swap_xor(int& x = 10, int& y = 5) {

  // Code to swap 'x' (1010) and 'y' (0101)
  x = x ^ y;  // x now becomes 15 (1111)
  y = x ^ y;  // y becomes 10 (1010)
  x = x ^ y;  // x becomes 5 (0101)

  printf("After Swapping: x = %d, y = %d", x, y);

}

void swap_sum(int& x = 10, int& y = 5) {
  // Code to swap 'x' and 'y'
  x = x + y;  // x now becomes 15
  y = x - y;  // y becomes 10
  x = x - y;  // x becomes 5

  printf("After Swapping: x = %d, y = %d", x, y);
}

}  // namespace swap_2_numbers_xor

#endif /* SWAP_2_NUMBERS_XOR_H_ */
