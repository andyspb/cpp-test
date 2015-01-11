/*
 * 17_1_swap_numbers_in_place.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _SWAP_NUMBERS_IN_PLACE_H_
#define _SWAP_NUMBERS_IN_PLACE_H_

namespace swwap_numbers {

void swap(int& a, int& b) {
 // Example for a = 9, b = 4
 a = a - b ; // a = 9 - 4 = 5
 b = a + b ; // b = 5 + 4 = 9
 a = b - a ; // a = 9 - 5
}

//We can implement a similar solution with bit manipulation. The benefit of this solution
//is that it works for more data types than just integers.
void swap_opt(int& a, int& b) {
  a = a^b; // a = 101A110 = 011
  b = a^b; // b = 011A110 = 101
  a = a^b; // a = 011A10l = 110
}

int test() {
  return 1;
}

}  // namespace swwap_numbers

#endif /* _SWAP_NUMBERS_IN_PLACE_H_ */
