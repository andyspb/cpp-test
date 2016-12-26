/*
 * interpolation_search.h
 *
 *  Created on: Apr 15, 2015
 *      Author: andy
 */

#ifndef INTERPOLATION_SEARCH_H_
#define INTERPOLATION_SEARCH_H_

#include <iostream>

namespace interpolation_search {

template<typename T>
int interpolationSearch(T * arr, int size, T key) {

  if (size < 0 || !arr) {  // not the best way to handle this case, but it
    return -1;             // serves to draw attention to it possibly happening.
  }
  unsigned long long low = 0;
  unsigned long long high = size - 1;
  unsigned long long mid;

  while (!(arr[high] == arr[low] || key < arr[low] || arr[high] < key)) {
    mid = low + (key - arr[low]) * ((high - low) / (arr[high] - arr[low]));

    if (arr[mid] < key)
      low = mid + 1;

    else if (key < arr[mid])
      high = mid - 1;

    else
      return mid;
  }

  if (key == arr[low])
    return low;

  else
    return -1;

}

int test() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::cout << "Interpolation search\n";
  int toFind = 6;
  int size = sizeof(arr) / sizeof(int);
  std::cout << "size=" << size << "\n";
  int res = interpolationSearch<int>(arr, size, toFind);
  std::cout << toFind << " found:" << res << "\n";

  return 1;
}

}  // namespace interpolation_search

#endif /* INTERPOLATION_SEARCH_H_ */
