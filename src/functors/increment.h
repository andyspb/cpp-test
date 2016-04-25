/*
 * increment.h
 *
 *  Created on: Apr 23, 2016
 *      Author: andy
 */

#ifndef SRC_FUNCTORS_INCREMENT_H_
#define SRC_FUNCTORS_INCREMENT_H_

#include <iostream>
#include <algorithm>

namespace increment {

int increment(int x) {
  return (x + 1);
}

TEST_RESULT test() {
  int arr[] = { 1, 2, 3, 4, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);

  // Apply increment to all elements of
  // arr[] and store the modified elements
  // back in arr[]
  std::transform(arr, arr + n, arr, increment);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  RETURN_OK();
}

}  // namespace increment

#endif /* SRC_FUNCTORS_INCREMENT_H_ */
