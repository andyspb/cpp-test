/*
 * find_elem_that_appears_once.h
 *
 *  Created on: 01 июля 2015 г.
 *      Author: andy
 */

#ifndef SRC_BITS_FIND_ELEM_THAT_APPEARS_ONCE_H_
#define SRC_BITS_FIND_ELEM_THAT_APPEARS_ONCE_H_

#include <stdio.h>

//Expected time complexity is O(n) and O(1) extra space.
//Examples:
//Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
//Output: 2

namespace find_elem_that_appears_once {

int getSingle(int arr[], int n) {
  int ones = 0, twos = 0;
  int common_bit_mask;
  // Let us take the example of {3, 3, 2, 3} to understand this
  for (int i = 0; i < n; i++) {
    twos = twos | (ones & arr[i]);
    ones = ones ^ arr[i];

    /* The common bits are those bits which appear third time
     So these bits should not be there in both 'ones' and 'twos'.
     common_bit_mask contains all these bits as 0, so that the bits can
     be removed from 'ones' and 'twos'

     Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
     after 1st, 2nd, 3rd and 4th iterations respectively */
    common_bit_mask = ~(ones & twos);

    /* Remove common bits (the bits that appear third time) from 'ones'

     Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
     2nd, 3rd and 4th iterations respectively */
    ones &= common_bit_mask;

    /* Remove common bits (the bits that appear third time) from 'twos'

     Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
     2nd, 3rd and 4th itearations respectively */
    twos &= common_bit_mask;

    // uncomment this code to see intermediate values
    //printf (" %d %d \n", ones, twos);
  }

  return ones;
}

}  // find_elem_that_appears_once

#endif /* SRC_BITS_FIND_ELEM_THAT_APPEARS_ONCE_H_ */
