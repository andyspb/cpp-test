/*
 * 5_3_next_prev_same_bits.h
 *
 *  Created on: 22 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _NEXT_PREV_SAME_BITS_H_
#define _NEXT_PREV_SAME_BITS_H_

//Given a positive integer, print the next smallest and the next largest number that
//have the same number of 7 bits in their binary representation.

namespace next_prev_same_bits {


int getNext(int n) {
 /* Compute c0 and c1 */
 int c = n;
 int c0 = 0;
 int c1 = 0;
 while (((c & 1) == 0) && (c != 0)) {
   c0++;
   c >>= 1;
 }
 while((c & 1) == 1) {
   c1++;
   c >>= 1;
 }
 /* Error: if n == 11..1100...00, then there is no bigger number
  * with the same number of 1s. */
 if (c0 + c1 == 31 || c0 + c1 == 0) {
   return -1;
 }

 int p = c0 + c1;// position of rightmost non-trailing zero
 n |= (1 << p); // Flip rightmost non-trailing zero
 n &= ~((1 << p) - 1); // Clear all bits to the right of p
 n |= (1 << (c1 - 1)) - 1; // Insert (cl-1) ones on the right.
 return n;
}


int getPrev(int n) {
  int temp = n;
  int c0 = 0;
  int c1 = 0;
  while (temp & 1 == 1 ) {
    c1++;
    temp >>= 1;
  }
  if (temp == 0)
    return -1;
  while (((temp & 1) == 0) && (temp != 0)) {
    c0++;
    temp >>= 1;
  }

  int p = c0 + c1; // position of rightmost non-trailing one
  n &= ((~0) << (p + 1)); // clears from bit p onwards
  int mask = (1 << (c1 + 1)) - 1; // Sequence of (cl+1) ones
  n = mask << (c0 - 1);
  return n;
}

int test() {

  return 1;
}


}  // namespace next_prev_same_bits



#endif /* _NEXT_PREV_SAME_BITS_H_ */
