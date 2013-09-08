#pragma once
#include <string>
#include <iostream>
#include <algorithm>
namespace string_test {

void test() {

  const char * ch = "hello";

  std::string str(ch);
  std::cout << str << std::endl;

  std::reverse(str.begin(), str.end());

  std::cout << str << std::endl;

  std::reverse(str.begin(), str.end());

  std::cout << str[1] << std::endl;

  std::cout << str.max_size() << "\n";

  char str_ch[] = "HELLO";
  char str_ch1[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
  string str_ch3("hello");

  str_ch[0] = 'a';
  std::cout << "strlen" << std::endl;
  std::cout << strlen(str_ch) << std::endl;
  std::cout << strlen(str_ch1) << std::endl;

  std::cout << "sizeof" << std::endl;
  std::cout << sizeof(str_ch) << std::endl;
  std::cout << sizeof(str_ch1) / sizeof(char) << std::endl;

}
}
