/*
 * 5_1_insert_n_to_m.h
 *
 *  Created on: 09 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _INSERT_N_TO_M_H_
#define _INSERT_N_TO_M_H_

//You are given two 32-bit numbers, N andM, and two bit positions, i and j. Write a
//method to insert M into Nsuch that M starts at bit j and ends at bit i. You can assume
//that the bits j through i have enough space to fit all ofM. That is, ifM= 10011,
//you can assume that there are at least 5 bits between j and i. You would not, for
//example, have j-3 and i=2, because M could not fully fit between bit 3 and bit 2.
//EXAMPLE:
//Input: N = 16000000000, M = 10011, i = 2, j = 6
//Output: N = 10001001100
//This problem can be approached in three key steps:
//1. Clear the bits j through i in N
//2. Shift M so that it lines up with bits j through i
//3. Merge M and N
namespace insert_n_to_m {

int updateBits(int n, int m, int i, int j) {
  /* Create a mask to clear bits i through j in n
   /* EXAMPLE: i = 2, j = 4. Result should be 11100011.
   * For simplicity, we'll use just 8 bits for the example.
   */
  int allOnes = ~0;  // will equal sequence of all Is

  // is before position j, then 0s. left = 11100000
  int left = allOnes << (j + 1);

  // I's after position i. right = 00000011
  int right = ((1 << i) - 1);

  // All Is, except for 0s between i and j. mask = 11100011
  int mask = left | right;

  /* Clear bits j through i then put m in there */
  int n_cleared = n & mask;  // Clear bits j through i.
  int m_shifted = m << i;  // Move m into correct position.

  return n_cleared | m_shifted;  // OR them, and we're done!
}

int test() {
  return 1;
}

}  // namespace insert_n_to_m



#endif /* 5_1_INSERT_N_TO_M_H_ */
