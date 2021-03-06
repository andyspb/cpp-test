/*
 * swap_two_nibbles_in_a_byte.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef SWAP_TWO_NIBBLES_IN_A_BYTE_H_
#define SWAP_TWO_NIBBLES_IN_A_BYTE_H_

#include <stdio.h>

namespace swap_two_nibbles_in_a_byte {

unsigned char swapNibbles(unsigned char x) {
  return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  unsigned char x = 100;
  printf("%u", swapNibbles(x));
  RETURN_OK();
}

}

#endif /* SWAP_TWO_NIBBLES_IN_A_BYTE_H_ */
