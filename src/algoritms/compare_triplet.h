/*
 * compare_triplet.h
 *
 *  Created on: Feb 20, 2018
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_COMPARE_TRIPLET_H_
#define SRC_ALGORITMS_COMPARE_TRIPLET_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

namespace compare_triplet {

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int *result_size) {
  // Complete this function
  __SCOPE_LOG__;
  int first[3] = { a0, a1, a2 };
  int second[3] = { b0, b1, b2 };
  static int pocket[2] = { 0, 0 };

  for (int count = 0; count < 3; ++count) {
    if (first[count] > second[count]) {
      ++pocket[0];
    } else if (first[count] < second[count]) {
      ++pocket[1];
    } else {
      continue;
    }
  }

  *result_size = 2;

  printf("result_size: %d\n", *result_size);

  return pocket;
}

int test() {
  __SCOPE_LOG__;

  int a0;
  int a1;
  int a2;
  scanf("%d %d %d", &a0, &a1, &a2);
  int b0;
  int b1;
  int b2;
  scanf("%d %d %d", &b0, &b1, &b2);
  int result_size = 0;
  int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
  for (int result_i = 0; result_i < result_size; result_i++) {
    if (result_i) {
      printf(" ");
    }
    printf("%d", result[result_i]);
  }
  puts("");


  return 1;
}

}  // namespace compare_triplet



#endif /* SRC_ALGORITMS_COMPARE_TRIPLET_H_ */
