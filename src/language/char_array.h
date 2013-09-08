#ifndef _CHAR_ARRAY_H_
#define _CHAR_ARRAY_H_

#include <iostream>

namespace char_array {
int test() {
  std::cout << "Test: char array --->" << std::endl;
  char test[] = "Hello";
  std::cout << "sizeof(test)=" << sizeof(test) /sizeof(test[0])<< std::endl;
  std::cout << "strlen(test)=" << strlen(test) << std::endl;
  char * ch = test;
  std::cout << "strlen(ch)=" << strlen(ch) << std::endl;
//		char myword1 [] = { 'H', 'e', 'l', 'l', 'o', '\0' };
//		char myword2 [] = "Hello";
  //
  //char mystext[];
  //mystext = "Hello";
//		char mystext2[] = "Hello";
  char * t = new char[7];
  char mystext1[] = { 0 };
  std::cout << "sizeof(mystext1)=" << sizeof(mystext1) << std::endl;
  delete[] t;
  return 1;
}
} // namespace char_array

#endif // _CHAR_ARRAY_H_
