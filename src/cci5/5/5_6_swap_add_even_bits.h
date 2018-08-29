/*
 * 5_6_swap_add_even_bits.h
 *
 *  Created on: 23 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _SWAP_ADD_EVEN_BITS_H_
#define _SWAP_ADD_EVEN_BITS_H_

// Write a program to swap odd and even bits in an integer with as few instructions as
// possible (e.g., bit 0 and b0it! are swapped, bit 2 and bit 3 are swapped, and so on).
// SOLUTION
// Like many of the previous problems, it's useful to think about this problem in a different
// way. Operating on individual pairs of bits would be difficult, and probably not that efficient
// either. So how else can we think about this problem?
// We can approach this as operating on the odds bits first, and then the even bits. Can
// we take a number n and move the odd bits over by 1 ? Sure. We can mask all odd bits
// with 10101010 in binary (which is 0xAA), then shift them right by 1 to put them in the
// even spots. For the even bits, we do an equivalent operation. Finally, we merge these

namespace swap_add_even_bits {

int swapOddEvenBits(int x) {
  return (((x & OxAAAAAAAA) >> 1) | ((x & 0x55555555) << 1));
}

}  // namespace swap_add_even_bits

#endif /* 5_6_SWAP_ADD_EVEN_BITS_H_ */
