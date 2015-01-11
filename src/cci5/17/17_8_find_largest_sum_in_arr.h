/*
 * 17_8_find_largest_sum_in_arr.h
 *
 *  Created on: 06 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _FIND_LARGEST_SUM_IN_ARR_H_
#define _FIND_LARGEST_SUM_IN_ARR_H_

namespace get_max_sum_in_array {

int getMaxSum(int a[], int size) {
  int maxsum = 0;
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += a[i];
    if (maxsum < sum) {
      maxsum = sum;
    } else if (sum < 0) {
      sum = 0;
    }
  }
  return maxsum;
}

int test() {
  return 1;
}

} //  namespace get_max_sum_in_array

#endif /* 17_8_FIND_LARGEST_SUM_IN_ARR_H_ */
