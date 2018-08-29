/*
 * best_path.h
 *
 *  Created on: 4 џэт. 2017 у.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_BEST_PATH_H_
#define SRC_ALGORITMS_BEST_PATH_H_

//Given: A matrix m x n of the integers {1,2,..., n*m}
//Output: The "best path" starting from the top left, going to the bottom right.
//a "path" is "better" than another one, if the list of numbers in the path, sorted, comes earlier lexicographically.
//
//Example:
//4 5 9
//8 1 3
//2 6 7
//
//4-5-9-3-7 sorted=> 3,4,5,7,9
//4-8-1-6-7 sorted=> 1,4,6,7,8
//4-5-1-3-7 sorted=> 1,3,4,5,7 <= smallest lexicographically.
#include <iostream>

namespace best_path {

#define MAX_N 3
#define MAX_M 3

int arr[MAX_N][MAX_M] = { { 4, 5, 9 }, { 8, 1, 3 }, { 2, 6, 7 } };

void fill_arr() {
//  arr[0][0] = 4;
//  arr[0][1] = 5;
//  arr[0][2] = 9;
//  arr[1][0] = 8;
//  arr[1][1] = 1;
//  arr[1][2] = 3;
//  arr[2][0] = 2;
//  arr[2][1] = 6;
//  arr[2][2] = 7;
}

void print_array(int (&arr)[MAX_N][MAX_M], int n = MAX_N, int m = MAX_M) {
  for (int i = 0; i < MAX_N; ++i) {
    for (int j = 0; j < MAX_M; ++j) {
      std::cout << arr[i][j] << " ";
    }
    std::endl(std::cout);
  }
}

void find_best_path(int (&arr)[MAX_N][MAX_M], int n = MAX_N, int m = MAX_M) {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int i = 0, j = 0;
  while (i < MAX_N && j < MAX_M) {
    std::cout << arr[i][j] << " ";
    if (arr[i][j + 1] < arr[i + 1][j]) {
      ++j;
    } else {
      ++i;
    }
  }
  while (++i < MAX_N)
    std::cout << arr[i][MAX_M - 1] << " ";
  while (++j < MAX_M) {
    std::cout << arr[MAX_N - 1][j] << " ";
  }
  std::endl(std::cout);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  fill_arr();
  print_array(arr);
  find_best_path(arr);

  RETURN_OK();
}
}

#endif /* SRC_ALGORITMS_BEST_PATH_H_ */
