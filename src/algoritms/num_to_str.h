#ifndef _NUM_TO_STR_H
#define _NUM_TO_STR_H

#include <iostream>
void Numbers2String(int number, char* str) {
  sprintf(str, "%d", number);
}

void Number2String2(int number, char* str) {
  //_itoa(number, str, 10);

}

void Integer2StringTest(int number) {
  std::cout << "Integer to string test" << std::endl;
  char _str[32], __str[32];
  Number2String2(number, _str);
  Numbers2String(number, __str);
  std::cout << "integer:" << number << " _str:" << _str << " __str:" << __str
            << std::endl;
}

#endif  // _NUM_TO_STR_H
