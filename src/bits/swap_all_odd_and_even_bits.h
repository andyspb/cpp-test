/*
 * swap_all_odd_and_even_bits.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef SWAP_ALL_ODD_AND_EVEN_BITS_H_
#define SWAP_ALL_ODD_AND_EVEN_BITS_H_

#include <stdio.h>

namespace swap_all_odd_and_even_bits {

unsigned int swap_bits(unsigned int x) {
  // Get all even bits of x
  unsigned int even_bits = x & 0xAAAAAAAA;

  // Get all odd bits of x
  unsigned int odd_bits = x & 0x55555555;

  even_bits >>= 1;  // Right shift even bits
  odd_bits <<= 1;   // Left shift odd bits

  return (even_bits | odd_bits);  // Combine even and odd bits
}

// Driver program to test above function
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  unsigned int x = 23;  // 00010111

  // Output is 43 (00101011)
  printf("%u ", swap_bits(x));

  RETURN_OK();
}

}  // namespace swap_all_odd_and_even_bits

#endif /* SWAP_ALL_ODD_AND_EVEN_BITS_H_ */
