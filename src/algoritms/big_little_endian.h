#ifndef _BIG_LITTLE_ENDIAN_H_
#define _BIG_LITTLE_ENDIAN_H_

#include <iostream>

namespace big_little_endian {

int test(void) {
  std::cout << "Test: big or little endian ---> " << std::endl;
  int num = 1;
  if (*(char *) &num == 1) {
    std::cout << "Little-Endian" << std::endl;
  } else {
    std::cout << "Big-Endian" << std::endl;
  }
  return 1;
}
}  //namespace big_little_endian
#endif // _BIG_LITTLE_ENDIAN_H_
