/*
 * reverse_string.h
 *
 *  Created on: 25 дек. 2014 г.
 *      Author: andy
 */

#ifndef REVERSE_STRING_H_
#define REVERSE_STRING_H_

#include <iostream>
//1.2 Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
//string.

namespace reverse_string {

void reverse_str(char* str) {
  std::cout << "reverse strlen(str)=" << strlen(str) << std::endl;
  if (!str || strlen(str)==1) {
    // nothing to reverse;
    return;
  }

  char* end = str;
  char tmp;
  while (*end) {
    ++end;
  }
  --end;
  while( str<end ) {
    tmp=*str;
    *str = *end;
    *end = tmp;
    ++str;
    --end;
  }
}


int test(){
  char str[] = "bla bla bla";
  std::cout << str << std::endl;
  reverse_str(str);
  std::cout << str << std::endl;
  return 1;
}

}

#endif /* REVERSE_STRING_H_ */
