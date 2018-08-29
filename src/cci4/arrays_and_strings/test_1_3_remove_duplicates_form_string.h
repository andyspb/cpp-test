#ifndef TEST_1_3_REMOVE_DUPLICATES_FORM_STRING_H_
#define TEST_1_3_REMOVE_DUPLICATES_FORM_STRING_H_

#include <iostream>
// Design an algorithm and write code to remove the duplicate characters
// in a string without using any additional buffer.
// NOTE: One or two additional variables are fine.
// An extra copy of the array is not fine.
// FOLLOW UP
// Write the test cases for this method

namespace test_1_3_remove_duplicates_form_string {

// For each character, check if it is a duplicate of already found characters
// Skip duplicate characters and update the non duplicate characters
void removeDuplicates(char* str, int size) {
  if (str == NULL) {
    std::cout << "str is null" << std::endl;
    return;
  }
  if (size < 2) {
    return;
  }
  int tail = 1;
  for (int i = 1; i < size; ++i) {
    int j;
    for (j = 0; j < tail; ++j) {
      if (str[i] == str[j]) {
        break;
      }
    }
    if (j == tail) {
      str[tail] = str[i];
      ++tail;
    }
  }
  str[tail] = 0;
}

int test() {
  std::cout << "Test 1.3" << std::endl;
//  1 String does not contain any duplicates, e g : abcd
//  2 String contains all duplicates, e g : aaaa
//  3 Null string
//  4 String with all continuous duplicates, e g : aaabbb
  char arr1[] = "abcd";
  std::cout << arr1 << ":";
  removeDuplicates(arr1, 4);
  std::cout << arr1 << std::endl;

  char arr2[] = "aaaa";
  std::cout << arr2 << ":";
  removeDuplicates(arr2, 4);
  std::cout << arr2 << std::endl;

  char* arr3 = 0;
  //std::cout << arr3 << ":";
  removeDuplicates(arr3, 0);
  //std::cout << arr3 << std::endl;

  char arr4[] = "aaaabbbb";
  std::cout << arr4 << ":";
  removeDuplicates(arr4, 8);
  std::cout << arr4 << std::endl;

  return 1;
}
}  // namesapce test_1_3

#endif /* TEST_1_3_REMOVE_DUPLICATES_FORM_STRING_H_ */
