//Write a method that will reverse a string.
#ifndef  _REVERSE_STRING_1_H_
#define _REVERSE_STRING_1_H_

#include <iostream>

namespace reverse_string_1 {

void reverse(char *str) {
  int length = static_cast<int>(strlen(str));
  if (length <= 1) {
    return;
  }
  char temp;
  for (int i = 0; i < length >> 1; ++i) {
    temp = str[length - i - 1];
    str[length - i - 1] = str[i];
    str[i] = temp;
  }
}

void reverse_rec(char *str) {
  if (*str) {
    reverse_rec(str + 1);
    putchar(*str);
  }
}

int test() {
  std::cout << "Reverse string test" << std::endl;
  char str[] = "This is a string for reverse.";
  std::cout << "Source str:\n" << str << std::endl;
  reverse(str);
  std::cout << "Reversed str:\n" << str << std::endl;
  // reverse back
  reverse(str);

  reverse_rec(str);
  std::cout << "Reversed with recursion:\n" << str << std::endl;
  std::cout << std::endl;
  return 1;
}

}  // namespace reverse_string_1

#endif _REVERSE_STRING_1_H_
