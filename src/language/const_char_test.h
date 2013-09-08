#ifndef CONST_CHAR_TEST_H
#define CONST_CHAR_TEST_H

#include <iostream>
namespace const_char_test {
int test() {
  std::cout << "const_char_test " << std::endl;
  char ch[] = "Hello";
  char wh[] = "World";
  const char * p0 = ch;
  char const * p1 = ch;
  char * const p2 = ch;
  const char * const p3 = ch;

  std::cout << ch << std::endl;
  std::cout << p0 << std::endl;
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;

  p0 = wh;
  *(p2+1 )= 'a';


  ch[3] = '_';
  //*(p1+2) = 't';
  // p2 = wh;
  *(p2 + 4) = 't';

  p1 = wh;
  std::cout << p1 << std::endl;

  //*(p3+2) = 'a';
  std::cout << ch << std::endl;
  std::cout << p0 << std::endl;
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
  return 1;
}
}  // namespace const_char_test

#endif  // CONST_CHAR_TEST_H
