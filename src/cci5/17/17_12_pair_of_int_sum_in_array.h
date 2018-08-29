/*
 * 17_12_pair_of_int_sum_in_array.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _PAIR_OF_INT_SUM_IN_ARRAY_H_
#define _PAIR_OF_INT_SUM_IN_ARRAY_H_

#include <algorithm>

namespace print_pair_sum {

void printPairSums(int array[], int size, int sum) {
  std::sort(array, array + size);
  int first = 0;
  int last = size - 1;
  while (first < last) {
    int s = array[first] + array[last];
    if (s == sum) {
      std::cout << array[first] << " " << array[last] << std::endl;
      first++;
      last--;
    } else {
      if (s < sum)
        first++;
      else
        last--;
    }
  }
}

}  // namespace print_pair_sum

#endif /* _PAIR_OF_INT_SUM_IN_ARRAY_H_ */
