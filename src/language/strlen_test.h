#ifndef STRLEN_TEST_H
#define STRLEN_TEST_H

#include <stdio.h>
#include <string.h>

namespace strlen_test {
int test() {
  const char * s1 = "1";
  char s2[] = "012345";

  std::cout << s1 << " strlen(s1) = " << strlen(s1) << std::endl;
  std::cout << s1 << " sizeof(s1) = " << sizeof(s1) << std::endl;
  std::cout << s2 << " strlen(s2) = " << strlen(s2) << std::endl;
  std::cout << s2 << " sizeof(s2) = " << sizeof(s2) << std::endl;
  std::cout << strlen("0123456789") << std::endl;
  return 1;
}
}  // namespace strlen_test

#endif  // STRLEN_TEST_H
