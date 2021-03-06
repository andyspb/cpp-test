#ifndef _PALINDROM_REC_H
#define _PALINDROM_REC_H

#include <iomanip>
#include <iostream>
#include <string>

namespace palindrom_rec {

bool isPalindrome(const std::string &str, int first, int last) {
  if (first == last)
    return true;
  else if (str[first] != str[last])
    return false;
  return isPalindrome(str, first + 1, last - 1);
}

bool palindrome(const std::string &str) {
  // empty string: exit or return false what ever you want
  if (str == "\0" || str == "")
    return false;
  else

    return isPalindrome(str, 0, (int) str.length() - 1);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::string str = "arosaupalanalapuasora";
  bool result = palindrome(str);

  LOG(INFO) << "Is palindrome(" << str << ") = " << std::boolalpha << result;

  str = "some test";
  result = palindrome(str);

  LOG(INFO) << "Is palindrome(" << str << ") = " << std::boolalpha << result;

  RETURN_OK();
}

}  // namespace palindrom_rec

#endif  // _PALINDROM_REC_H
