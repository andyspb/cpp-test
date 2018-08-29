/*
 * array.h
 *
 *  Created on: May 9, 2017
 *      Author: andy
 */

#ifndef SRC_COMMON_ARRAY_ARRAY_H_
#define SRC_COMMON_ARRAY_ARRAY_H_

// forward declzarations
template<typename T>
void print_array(T* arr, size_t size);

// implementation
template<typename T>
void print_array(T* arr, size_t size) {
  for (size_t s = 0; s < size; ++s) {
    std::cout << arr[s] << " ";
  }
  std::endl(std::cout);
}

#endif /* SRC_COMMON_ARRAY_ARRAY_H_ */
