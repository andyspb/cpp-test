/*
 * binary_search.h
 *
 *  Created on: 06 ���. 2015 �.
 *      Author: andy
 */

#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <climits>
#include <iostream>

namespace binary_search {

#define KEY_NOT_FOUND INT_MAX

// recursive
int binary_search_rec(int arr[], int key, int min, int max) {
  // test if array is empty
  if (max < min) {  // set is empty, so return value showing not found
    return KEY_NOT_FOUND;
  } else {
    int mid = min - ((min - max) / 2);
    // three-way comparison
    if (arr[mid] > key)
      // key is in lower subset
      return binary_search_rec(arr, key, min, mid - 1);
    else if (arr[mid] < key)
      // key is in upper subset
      return binary_search_rec(arr, key, mid + 1, max);
    else
      // key has been found
      return mid;
  }
}

// iterate
int binary_search_iter(int arr[], int key, int min, int max) {
  // continue searching while [imin,imax] is not empty
  while (max >= min) {
      // calculate the midpoint for roughly equal partition
      int mid = min - (min - max)/2;
      if(arr[mid] == key)
        // key found at index imid
        return mid;
      // determine which subarray to search
      else if (arr[mid] < key)
        // change min index to search upper subarray
        min = mid + 1;
      else
        // change max index to search lower subarray
        max = mid - 1;
    }
  // key was not found
  return KEY_NOT_FOUND;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  int arr[] = {1,2,3,5,6,7,8,9,11,22,33,44,55};

  int rec = binary_search_rec(arr, 33, 0, 13);
  std::cout << "rec=" << rec << std::endl;

  int iter = binary_search_iter(arr, 33, 0, 13);
  std::cout << "iter=" << iter << std::endl;

  std::cout << "<<<" << std::endl;
  RETURN_OK();
}


}  // namespace binary_search

#endif /* BINARY_SEARCH_H_ */
