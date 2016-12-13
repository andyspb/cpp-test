/*
 * shell_sort.h
 *
 *  Created on: 25 џэт. 2015 у.
 *      Author: andy
 */

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

namespace shellsort {

#include  <iostream>

/* function to sort arr using shellSort */
int shell_sort(int arr[], int n) {
  // Start with a big gap, then reduce the gap
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; ++i) {
      int j, temp = arr[i];
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
  return 0;
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::endl(std::cout);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  int arr[] = { 12, 34, 54, 2, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);

  LOG(INFO) << "Array before sorting:";
  print_array(arr, n);
  shell_sort(arr, n);
  LOG(INFO) << "Array after sorting:";
  print_array(arr, n);
  RETURN_OK();
}
}  // namespace shell_sort
#endif /* SHELL_SORT_H_ */
