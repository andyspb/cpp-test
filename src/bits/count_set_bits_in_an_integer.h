/*
 * count_set_bits_in_an_integer.h
 *
 *  Created on: 02 ����. 2015 �.
 *      Author: andy
 */

#ifndef COUNT_SET_BITS_IN_AN_INTEGER_H_
#define COUNT_SET_BITS_IN_AN_INTEGER_H_

#include<stdio.h>

namespace count_set_bits_in_an_integer {

int countSetBits(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

/* Program to test function countSetBits */
int test1() {
  int i = 9;
  printf("%d", countSetBits(i));
  getchar();
  return 1;
}

// Brian Kernighan�s Algorithm:

/* Function to get no of set bits in binary
 representation of passed binary no. */
int countSetBits2(int n) {
  unsigned int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}

/* Program to test function countSetBits */
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int i = 9;
  printf("%d", countSetBits2(i));
  getchar();
  RETURN_OK();
}

}  // count_set_bits_in_an_integer

#endif /* COUNT_SET_BITS_IN_AN_INTEGER_H_ */
