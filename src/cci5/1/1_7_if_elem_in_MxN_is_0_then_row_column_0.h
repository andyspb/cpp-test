/*
 * 1_7_if_elem_in_MxN_is_0_then_row_column_0.h
 *
 *  Created on: 26 дек. 2014 г.
 *      Author: andy
 */

#ifndef _IF_ELEM_IN_MXN_IS_0_THEN_ROW_COLUMN_0_H_
#define _IF_ELEM_IN_MXN_IS_0_THEN_ROW_COLUMN_0_H_

#include <iostream>

namespace set_matrix_col_row_zero {

void print_array(int** matrix, int n) {
  if (!matrix || !*matrix)
    return;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void setZeros(int** matrix, int size) {
  bool row[3] = { 0 };
  bool column[3] = { 0 };

  // Store the row and column index with value 0
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (matrix[i][j] == 0) {
        row[i] = true;
        column[j] = true;
      }
    }
  }

  // Set arr[i][j] to 0 if either row i or column j has a 0
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (row[i] || column[j]) {
        matrix[i][j] = 0;
      }
    }
  }
}

int test() {
  const int size = 3;
  int **array = new int *[size];
  for (int i = 0; i < size; i++)
    array[i] = new int[size];
  int count = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      array[i][j] = ++count;
      if ((count & 10) == 0) {
        array[i][j] = 0;
      }
    }
  }
  print_array(array, size);
  setZeros(array, size);

  std::cout << "after set zeros" << std::endl;
  print_array(array, size);

  return 1;
}

}  // namespace set_matrix_col_row_zero

#endif /* _ELEM_IN_MXN_IS_0_THEN_ROW_COLUMN_0_H_ */
