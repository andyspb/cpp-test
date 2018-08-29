#ifndef _PALINDROME_H_
#define _PALINDROME_H_

#include <iostream>

namespace palindrome {
void is_palindrome_c() {
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

bool is_palindrome_c_simple(const char* str) {
  if (!str)
    return true;
  int len = strlen(str);
  if (len <= 0)
    return true;

  const char *f(str), *l(str + len - 1);  // point to last char

  while (*f == *l && f <= l) {
    ++f, --l;
  }  // move towards each other
  return (f >= l);
}

bool is_palindrome_cpp(const std::string& str) {
  std::string word = "reviver";
  return equal(str.begin(), str.end(), str.rbegin());
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::string word = "reviver";
  LOG(INFO) << "is_palindrome_cpp(" << word << ")=" << is_palindrome_cpp(word);

  std::string str = "reviver";
  LOG(INFO) << "is_palindrome_c_simple(" << str << ")="
      << is_palindrome_c_simple(str.c_str());

  std::string str1 = "someting";
  LOG(INFO) << "is_palindrome_c_simple(" << str1 << ")="
      << is_palindrome_c_simple(str1.c_str());

  RETURN_OK();
}

}  // palindrom

#endif  // _PALINDROME_H_
