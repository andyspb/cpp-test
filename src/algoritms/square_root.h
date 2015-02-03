#ifndef _SQUARE_ROOT_H_
#define _SQUARE_ROOT_H_

//algorithm to calculate the square root of a number
//Parameters and return code should be a float.
//Take into consideration exception handling for negative arguments and  speed.
#include <math.h>
#include <iostream>

namespace square_root {
float sqroot2(float m) {
  if (m < 0) {
    return -1;
  }
  if (m == 0) {
    return 0;
  }
  float x = m;
  for (int i = 0; i < 1000; i++) {
    x = (x + (m / x)) / 2;
  }
  return x;
}

float sqroot(float m) {
  if (m < 0) {
    return -1;
  }
  if (m == 0) {
    return 0;
  }
  float i = 0;
  float x1, x2;
  while ((i * i) <= m) {
    i += 0.1;
  }
  x1 = i;
  for (int j = 0; j < 100; j++) {
    x2 = m;
    x2 /= x1;
    x2 += x1;
    x2 /= 2;
    x1 = x2;
  }
  return x2;
}

int test() {
  std::cout << "Test: square root --->" << std::endl;
  for (int m = 0; m < 225; m += 15) {
    std::cout << "number=" << m << " using std::sqrt() " << std::sqrt(m)
              << std::endl;
    std::cout << "number=" << m << " using sqroot()" << sqroot(m) << std::endl;
    std::cout << "number=" << m << " using sqroot2()" << sqroot2(m)
              << std::endl;
  }
  return 1;
}
}  //namespace square_root
#endif // _SQUARE_ROOT_H_
