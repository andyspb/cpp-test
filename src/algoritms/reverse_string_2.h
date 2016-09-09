#ifndef  _SRC_ALGORITMS_REVERSE_STRING_2_H_
#define _SRC_ALGORITMS_REVERSE_STRING_2_H_

#include <string>
#include <iostream>
#include <algorithm>

namespace reverse_string_2 {
TEST_RESULT test() {
  __SCOPE_LOG__;

  std::string hello("Hello, how are you?");

  std::string s(hello.begin(), hello.end());
  std::string r(s);
  std::reverse(r.begin(), r.end());

  std::cout << "s: " << s << std::endl;
  std::cout << "r: " << r << std::endl;

  // iterate through all of the characters
  std::string::iterator pos;
  for (pos = s.begin(); pos != s.end(); ++pos) {
    std::cout << *pos;
  }
  std::endl(std::cout);
  std::reverse(s.begin(), s.end());
  std::cout << "reverse:       " << s << std::endl;
  RETURN_OK();
}
}  // namespace reverse_string_2

#endif // _SRC_ALGORITMS_REVERSE_STRING_H_
