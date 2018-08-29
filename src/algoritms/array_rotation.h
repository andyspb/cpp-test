/*
 * array_rotation.h
 *
 *  Created on: Feb 17, 2018
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_ARRAY_ROTATION_H_
#define SRC_ALGORITMS_ARRAY_ROTATION_H_

#include <iostream>

namespace array_rotation {

void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i)
    std::cout << arr[i] << " ";
  std::endl(std::cout);
}

int test() {
  __SCOPE_LOG__;
  return 1;
}


}  // namespace array_rotation

#endif /* SRC_ALGORITMS_ARRAY_ROTATION_H_ */
