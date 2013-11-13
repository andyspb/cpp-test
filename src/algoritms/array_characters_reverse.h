#ifndef _ARRAY_CHARACTERS_REVERSE_H
#define _ARRAY_CHARACTERS_REVERSE_H

#include <stdio.h>
#include <iostream>

//Given an array of characters. How would you reverse it. ?
//How would you reverse it without using indexing in the array.
namespace array_characters_reverse {

int test() {
  std::cout << "Test: Reverse characters in array" << std::endl;
  char str[] = { 'a', 'b', 'c', 'd', 'e' };
  unsigned int size = sizeof(str) / sizeof(str[0]);
  for (unsigned int i = 0; i < size; i++) {
    printf(" %c", str[i]);
  }
  std::endl(std::cout);
  char *a = str;
  char *b = str + (size - 1);

  while (a < b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    ++a;
    --b;
  }
  for (unsigned int i = 0; i < size; i++) {
    std::cout << " " << str[i];
  }
  std::endl(std::cout);
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // namespace array_characters_reverse

#endif //_ARRAY_CHARACTERS_REVERSE_H
