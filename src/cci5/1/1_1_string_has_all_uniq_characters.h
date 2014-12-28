/*
 * algo_if_string_has_all_uniq_characters.h
 *
 *  Created on: 25 дек. 2014 г.
 *      Author: andy
 */

#ifndef ALGO_IF_STRING_HAS_ALL_UNIQ_CHARACTERS_H_
#define ALGO_IF_STRING_HAS_ALL_UNIQ_CHARACTERS_H_

#include <iostream>

namespace str_has_uniq_chars {

bool isUniqueChars(char* str) {
  bool char_set[256] = { 0 };
  for (unsigned i = 0; i < strlen(str); ++i) {
    int val = int(str[i]);
    if (char_set[val])
      return false;
    char_set[val] = true;
  }
  return true;
}

int test() {
  char test[] = "abcd";

  std::cout << test << "all uniq chars: " << isUniqueChars(test)<< std::endl;
  char test2[] = "abbd";
  std::cout << test2 << "all uniq chars: " << isUniqueChars(test2) << std::endl;
  return 1;
}

}  // if_all_chars_uniq

#endif /* ALGO_IF_STRING_HAS_ALL_UNIQ_CHARACTERS_H_ */
