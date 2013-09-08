#ifndef STRLEN_H_
#define STRLEN_H_

#include <stdio.h>
#include <iostream>

namespace strlen_ {

int test() {
  const char *s1 = "aaaaaaaaaa";
  char s2[] = "tst";

  std::cout << "strlen(s1) = " << strlen(s1) << std::endl;
  std::cout << "sizeof(s1) = " << sizeof(s1) << std::endl;
  std::cout << "strlen(s2) = " << strlen(s2) << std::endl;
  std::cout << "sizeof(s2) = " << sizeof(s2) << std::endl;
  return 1;
}
}  // namespace strlen_

#endif /* STRLEN_H_ */
