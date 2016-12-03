/*
 * sum_array.h
 *
 *  Created on: Apr 14, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_SUM_ARRAY_H_
#define SRC_ALGORITMS_SUM_ARRAY_H_

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace sum_array {
int print_arr(std::vector<int>& arr) {
  int sum(0);
  for (size_t i = 0; i < arr.size(); ++i) {
    sum += arr[i];
  }
//    return sum;
  return ::std::accumulate(arr.begin(), arr.end(), 0);
}
TEST_RESULT test() {
  __SCOPE_LOG__;
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int arr_i = 0; arr_i < n; arr_i++) {
    std::cin >> arr[arr_i];
  }
  std::cout << print_arr(arr) << std::endl;
  RETURN_OK();
}
}  // namespace sum_array

#endif /* SRC_ALGORITMS_SUM_ARRAY_H_ */
