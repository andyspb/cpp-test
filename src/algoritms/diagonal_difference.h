/*
 * diagonal_difference.h
 *
 *  Created on: Feb 20, 2018
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_DIAGONAL_DIFFERENCE_H_
#define SRC_ALGORITMS_DIAGONAL_DIFFERENCE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

namespace diagonal_difference {
//Given a square matrix of size , calculate the absolute difference between the sums of its diagonals.

int diagonalDifference(int a_size_rows, int a_size_cols, int **a) {
  // Complete this function
  int d1 = 0, d2 = 0;
  for (int i = 0; i < a_size_rows; i++) {
    d1 += a[i][i];
    d2 += a[i][a_size_rows - i - 1];
  }
  return abs(d1 - d2);
}


int test() {

  int n;
  scanf("%i", &n);
  int a[n][n];
  for (int a_i = 0; a_i < n; a_i++) {
    for (int a_j = 0; a_j < n; a_j++) {

      scanf("%i", &a[a_i][a_j]);
    }
  }
  int result = diagonalDifference(n, n, a);
  printf("%d\n", result);

  return 1;
}

}  // namespace diagonal_difference



#endif /* SRC_ALGORITMS_DIAGONAL_DIFFERENCE_H_ */
