#ifndef _PALINDROME_H_
#define _PALINDROME_H_

#include <iostream>

namespace palindrom {
void test() {
  char strn[] = "a rosa upala na lapu asora";
  char *first_char = strn;  // point to first char
  char *last_char = strn + strlen(strn) - 1;  // point to last char

  while (*first_char == *last_char && first_char != last_char) {
    ++first_char, --last_char;
    while (*first_char == ' ')
      ++first_char;
    while (*last_char == ' ')
      --last_char;
  }  // move towards each other
  bool flag = (first_char == last_char);
  if (!flag) {
    std::cout << " Not a ";
  }
  std::cout << "Palindrome" << std::endl;
}

void test1() {
  std::string word = "reviver";
  bool is_palindrome = equal(word.begin(), word.end(), word.rbegin());
  std::cout << is_palindrome << std::endl;
}
}  // palindrom

#endif  // _PALINDROME_H_
