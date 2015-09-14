/*
 * is_div_by_9.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef IS_DIV_BY_9_H_
#define IS_DIV_BY_9_H_

#include<iostream>
using namespace std;

namespace is_div_by_9 {

// Bitwise operator based function to check divisibility by 9
bool isDivBy9(int n) {
  // Base cases
  if (n == 0 || n == 9)
    return true;
  if (n < 9)
    return false;

  // If n is greater than 9, then recur for [floor(n/9) - n%8]
  return isDivBy9((int) (n >> 3) - (int) (n & 7));
}

bool isDivBy9_iter(int n) {
  while (n > 9) {
    n = ((int) (n >> 3) - (int) (n & 7));
  }
  if (n == 0 || n == 9)
    return true;
  else
    //n is automatically less than 9 here
    return false;
}

#define div(x) x%9?0:1



// Driver program to test above function
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  // Let us print all multiples of 9 from 0 to 100
  // using above method
  for (int i = 0; i < 100; i++)
    if (isDivBy9(i))
      cout << i << " ";
  RETURN_OK();
}

}  // namespace is_div_by_9

#endif /* IS_DIV_BY_9_H_ */
