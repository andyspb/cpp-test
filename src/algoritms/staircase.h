/*
 * staircase.h
 *
 *  Created on: Apr 24, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_STAIRCASE_H_
#define SRC_ALGORITMS_STAIRCASE_H_

#include <iostream>

// Your teacher has given you the task of drawing a staircase structure.
// Being an expert programmer, you decided to make a program to draw it for you instead.
// Given the required height, can you print a staircase as shown in the example?
//
// Input
// You are given an integer NN depicting the height of the staircase.
//
// Output
// Print a staircase of height NN that consists of # symbols and spaces.
// For example for N=6N=6, here's a staircase of that height:

namespace staircase {

void print_stair(int n) {
  if (n < 1)
    return;
  for (int i = 1; i <= n; ++i) {
    for (int j = n - i; j > 0; --j) {
      std::cout << " ";
    }
    for (int j = 1; j <= i; ++j) {
      std::cout << "#";
    }
    std::endl(std::cout);
  };
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  print_stair(6);
  RETURN_OK();
}
}  // staircase

#endif /* SRC_ALGORITMS_STAIRCASE_H_ */
