/*
 * swap_bits.h
 *
 *  Created on: 25 ���. 2015 �.
 *      Author: andy
 */

#ifndef SWAP_BITS_H_
#define SWAP_BITS_H_
#include<stdio.h>

namespace swap_bits {

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n) {
  /* Move all bits of first set to rightmost side */
  unsigned int set1 = (x >> p1) & ((1U << n) - 1);

  /* Moce all bits of second set to rightmost side */
  unsigned int set2 = (x >> p2) & ((1U << n) - 1);

  /* XOR the two sets */
  unsigned int xor_ = (set1 ^ set2);

  /* Put the xor bits back to their original positions */
  xor_ = (xor_ << p1) | (xor_ << p2);

  /* XOR the 'xor' with the original number so that the
   two sets are swapped */
  unsigned int result = x ^ xor_;

  return result;
}

/* Drier program to test above function*/
int main() {
  int res = swapBits(28, 0, 3, 2);
  printf("\nResult = %d ", res);
  return 0;
}

}

#endif /* SWAP_BITS_H_ */
