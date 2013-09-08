// tests19.h
// author: andrey.krutogolov@gmail.com
// date:   04.04.2013


#ifndef TESTS19_H_
#define TESTS19_H_

#include <iostream>
#include <limits>
#include <float.h>

//#include "misc_log_ex.h"

namespace tests19 {

int main() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsequence-point"

  int i = 5;
  int j = i++ + ++i;
  std::cout << "j=" << j <<std::endl;

  volatile int u = 0;
//  u = u++ + ++u;
  u = u++ + ++u;
  std::cout << "u=" << u << std::endl;

  int uu = 0;
  uu = uu++ + ++uu;
  std::cout << "uu=" << uu << std::endl;

  int u1 = 0;
  u1 = u1++ + ++u1;
  std::cout << "u1=" << u1 << std::endl;

  int ii = 5;
  ii = (++ii) + (++ii) + (++ii);
  std::cout << "ii=" << ii <<std::endl;

//  float f = std::numeric_limits<float>::max();
  float f = FLT_MAX;

  float f1 = f + 1;

  if ( f == f1) {
    std::cout << "f == f1\n";
  } else {
    std::cout << "f != f1\n";
  }

#pragma GCC diagnostic pop

  return 0;
}

}  // namespace tests19



#endif  // TESTS19_H_
