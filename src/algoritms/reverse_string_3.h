/*
 * revers_String.h
 *
 *  Created on: Apr 21, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_REVERSE_STRING_3_H_
#define SRC_ALGORITMS_REVERSE_STRING_3_H_

namespace reverse_string_3 {

// Function to reverse a string
void reverse_string_3(std::string &str) {
  int n = str.length();

  // Swap character starting from two
  // corners
  for (int i = 0; i < n / 2; ++i) {
//    LOG(INFO) << str[i] << " " << str[n - i - 1] << std::endl;
    std::swap(str[i], str[n - i - 1]);
  }
}

// Driver program
TEST_RESULT test() {
  __SCOPE_LOG__;
  std::string str = "geeksforgeeks";
  std::cout << str << std::endl;
  reverse_string_3(str);
  std::cout << str << std::endl;
  RETURN_OK();
}

}  // namespace reverse_string_3

#endif /* SRC_ALGORITMS_REVERSE_STRING_3_H_ */
