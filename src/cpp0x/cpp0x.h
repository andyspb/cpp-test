//  cpp0x.h
//  author: andrey.krutogolov@gmail.com
//  date:   03.02.2013
//  тест
#ifndef CPP0X_H_
#define CPP0X_H_

#include "cpp0x_thread.h"

#include <assert.h>
#include <iostream>


namespace cpp0x {

int test() {
  std::cout << "Test cpp0x: \n";
  assert(cpp0x_thread::test());
  return 1;
}

}  // namespace cpp0x

#endif  // CPP0X_H_
