#ifndef _PALINDROME_H_
#define _PALINDROME_H_

#include <iostream>

namespace palindrom {
void test() {
  char strn[] = "a rosa upala na lapu asora";
  char *s = strn;  // point to first char
  char *e = strn + strlen(strn) - 1;  // point to last char

  while (*s == *e && s != e) {
    ++s, --e;
    while (*s == ' ')
      ++s;
    while (*e == ' ')
      --e;
  }  // move towards each other
  bool flag = (s == e);
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
