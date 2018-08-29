/*
 * string_permutation_of_other.h
 *
 *  Created on: 25 дек. 2014 г.
 *      Author: andy
 */

#ifndef STRING_PERMUTATION_OF_OTHER_H_
#define STRING_PERMUTATION_OF_OTHER_H_

#include <iostream>

namespace string_permutation_of_other {

bool is_string_permutation_of_other(char* str1, char* str2) {
//  std::cout << str1 << "  " << str2 << std::endl;
  std::sort(str1, str1 + sizeof(char) * (strlen(str1)));
  std::sort(str2, str2 + sizeof(char) * strlen(str2));
  return strcmp(str1, str2) == 0;
}

int test() {
  char str1[] = "dog";
  char str2[] = "god";
  std::cout << str1 << " is permutation of " << str2 << " :";
  bool b = is_string_permutation_of_other(str1, str2);
  std::cout << b << std::endl;
  return 1;
}

}

#endif /* STRING_PERMUTATION_OF_OTHER_H_ */
