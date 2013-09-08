#ifndef  _REVERSE_STRING_H_
#define _REVERSE_STRING_H_

#include <string>
#include <iostream>
#include <algorithm>

namespace reverse_string {
int test() {
  std::string hello("Hello, how are you?");

  std::string s(hello.begin(), hello.end());

  // iterate through all of the characters
  std::string::iterator pos;
  for (pos = s.begin(); pos != s.end(); ++pos) {
    std::cout << *pos;
  }
  std::endl(std::cout);
  reverse(s.begin(), s.end());
  std::cout << "reverse:       " << s << std::endl;
  return 1;
}
} // namespace reverse_string

#endif // _REVERSE_STRING_H_
