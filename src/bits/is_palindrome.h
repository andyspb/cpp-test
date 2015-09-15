/*
 * is_palindrome.h
 *
 *  Created on: 01 ����. 2015 �.
 *      Author: andy
 */

#ifndef IS_PALINDROME_H_
#define IS_PALINDROME_H_

#include <iostream>

namespace is_palindrome {

// This function returns true if k'th bit in x is set (or 1).
// For example if x (0010) is 2 and k is 2, then it returns true
bool isKthBitSet(unsigned int x, unsigned int k) {
  return (x & (1 << (k - 1))) ? true : false;
}

// This function returns true if binary representation of x is
// palindrome. For example (1000...001) is paldindrome
bool isPalindrome(unsigned int x) {
  int l = 1;  // Initialize left position
  int r = sizeof(unsigned int) * 8;  // initialize right position

  // One by one compare bits
  while (l < r) {
    if (isKthBitSet(x, l) != isKthBitSet(x, r))
      return false;
    l++;
    r--;
  }
  return true;
}

// Driver program to test above function
TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  unsigned int x = (1 << 15) + (1 << 16);
  std::cout << x << " is palindrome: " << isPalindrome(x) << std::endl;
  x = (1 << 31) + 1;
  std::cout << x << " is palindrome: " << isPalindrome(x) << std::endl;
  RETURN_OK();
}

}

#endif /* IS_PALINDROME_H_ */
