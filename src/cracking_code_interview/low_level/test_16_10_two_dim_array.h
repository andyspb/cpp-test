/*
 * test_16_10_two_dim_array.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */

#ifndef TEST_16_10_TWO_DIM_ARRAY_H_
#define TEST_16_10_TWO_DIM_ARRAY_H_

#include <malloc.h>
#include <iostream>

namespace test_16_10_two_dim_array {

int** My2DAlloc(int rows, int cols) {
  int header = rows * sizeof(int*);
  int data = rows * cols * sizeof(int);
  int** rowptr = (int**) malloc(header + data);
  int* buf = (int*) (rowptr + rows);
  int k;
  for (k = 0; k < rows; ++k) {
    rowptr[k] = buf + k * cols;
  }
  return rowptr;
}

int test() {
  std::cout << "test_16_10_two_dim_array:" << std::cout;

  int ** arr = My2DAlloc(10, 10);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << arr[i][j] << " ";
    }
    std::endl(std::cout);
  }
  return 1;
}
}  // test_16_10_two_dim_array

#endif /* TEST_16_10_TWO_DIM_ARRAY_H_ */
