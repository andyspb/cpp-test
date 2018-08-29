#ifndef TEST_1_5_REPLACE_ALL_SPACES_IN_STRING_WITH_PERS20_H_
#define TEST_1_5_REPLACE_ALL_SPACES_IN_STRING_WITH_PERS20_H_

#include <iostream>
// The algorithm is as follows:
// Count the number of spaces during the first scan
// of the string Parse the string again from the end and for each character:
// If a space is encountered, store Ò%20Ó
// Else, store the character as it is in the newly shifted location

namespace test_1_5_replace_all_spaces_in_string_with_pers20 {
void replace(char str[], int length) {
  int spaceCount = 0, newLength, i = 0;
  for (i = 0; i < length; ++i) {
    if (str[i] == ' ') {
      ++spaceCount;
    }
  }
  newLength = length + (2 * spaceCount);
  str[newLength] = '\0';
  for (i = length - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[newLength - 1] = '0';
      str[newLength - 2] = '2';
      str[newLength - 3] = '%';
      newLength = newLength - 3;
    } else {
      str[newLength - 1] = str[i];
      newLength = newLength - 1;
    }
  }
}

int test() {
  std::cout << "Test 1.4" << std::endl;
  char str[] = "my test";
  std::cout << str << ":";
  replace(str, 8);
  std::cout << str << std::endl;
  return 1;
}
}  // namespace test_1_5

#endif /* TEST_1_5_REPLACE_ALL_SPACES_IN_STRING_WITH_PERS20_H_ */
