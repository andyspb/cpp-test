/*
 * permutation_of_string.h
 *
 *  Created on: 25 џэт. 2015 у.
 *      Author: andy
 */

#ifndef PERMUTATION_OF_STRING_H_
#define PERMUTATION_OF_STRING_H_

namespace permutation_of_string {

#include <stdio.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(char *a, int i, int n) {
  int j;
  if (i == n) {
    printf("%s\n", a);
  }
  else {
    for (j = i; j <= n; ++j) {
      swap((a + i), (a + j));
      permute(a, i + 1, n);
      swap((a + i), (a + j));  //backtrack
    }
  }
}

/* Driver program to test above functions */
int test() {
  char a[] = "ABCD";
  permute(a, 0, 2);
  return 1;
}
}  // permutation_of_string

#endif /* PERMUTATION_OF_STRING_H_ */
