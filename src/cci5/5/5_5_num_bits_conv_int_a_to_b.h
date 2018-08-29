/*
 * 5_5_num_bits_conv_int_a_to_b.h
 *
 *  Created on: 23 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _NUM_BITS_CONV_INT_A_TO_B_H_
#define _NUM_BITS_CONV_INT_A_TO_B_H_

namespace num_bits_conv_int_a_to_b {

int bitSwapRequired(int a, int b) {
  int count = 0;
  for (int c = a ^ b; c != 0; c = c >> 1) {
    count += c & 1;
  }
  return count;
}

int bitSwapRequired2(int a, int b) {
  int count = 0;
  for (int c = a ^ b; c != 0; c = c & (c - 1)) {
    count++;
  }
  return count;
}

}  // namespace num_bits_conv_int_a_to_b

#endif /* 5_5_NUM_BITS_CONV_INT_A_TO_B_H_ */
