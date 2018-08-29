/*
 * 1_4_replace_spac_to_20.h
 *
 *  Created on: 26 дек. 2014 г.
 *      Author: andy
 */

#ifndef _REPLACE_SPACE_TO_20_H_
#define _REPLACE_SPACE_TO_20_H_

#include <iostream>

namespace replaceSpaces {

char* replaceSpacesTo20(char* str) {
  int spaceCount(0), newLength(0), i;
  int length = strlen(str);
  char* ret;
  for (i = 0; i < length; ++i) {
    if (str[i] == ' ')
      ++spaceCount;

  }
  newLength = length + spaceCount * 2;
  ret = new char[newLength * (sizeof(char))];
  if (!ret) {
    return 0;
  }
  i = 0;
  char * tmp = ret;
  while (i < length) {
    ++i;
    char ch = *str++;
    if (ch != ' ') {
      *tmp++ = ch;
    } else {
      *tmp++ = '%';
      *tmp++ = '2';
      *tmp++ = '0';
    }
  }
  *tmp = '\0';
  return ret;
}

int test() {
  char str[] = "This is a test string";

  std::cout << str << std::endl;
  char* result = replaceSpacesTo20(str);
  if (result) {
    std::cout << result << std::endl;
    delete result;
  }
  return 1;
}

}

#endif /* _REPLACE_SPACE_TO_20_H_ */
