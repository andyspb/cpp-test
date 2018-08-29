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
  const int half_size = length >> 1;
  for (int i = 0; i < half_size; ++i) {
    char temp = str[length - i - 1];
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

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::cout << "Reverse string test" << std::endl;
  char str[] = "This is a string for reverse.";
  std::cout << "Source string:\n" << str << std::endl;
  reverse(str);
  std::cout << "Reversed string:\n" << str << std::endl;
  // reverse back for next test
  reverse(str);
  std::cout << "Recursively reversed string:\n";
  reverse_rec(str);
  std::endl(std::cout);
  std::cout << "end of the test" << std::endl;
  RETURN_OK();
}

}  // namespace reverse_string_1

#endif // _REVERSE_STRING_1_H_
