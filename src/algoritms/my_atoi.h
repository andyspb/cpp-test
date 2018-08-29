#ifndef MY_ATOI_H
#define MY_ATOI_H

#include <iostream>
//atoi implementation

namespace my_atoi {
int test() {
  std::cout << "Test: my _atoi realization" << std::endl;
  char in[] = "123456";
  std::cout << "input: " << in << std::endl;
  int iRetVal = 0;

  char* pStr = in;
  if (pStr) {
    while (*pStr && *pStr <= '9' && *pStr >= '0') {
      iRetVal = (iRetVal * 10) + (*pStr - '0');
      pStr++;
    }
  }
  std::cout << "output: " << iRetVal << std::endl;
  std::cout << "<--- passed" << std::endl;
  return 1;
}
}  // my_atoi

#endif /// MY_ATOI_H
