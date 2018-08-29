#ifndef _BRAINBENCH_2_H_
#define _BRAINBENCH_2_H_

#include <iostream>

namespace brainbench_2 {
int test() {
  double x, y;
  x = 1.0;
  y = 2.0;
  double z = (double) ((int) x / (int) y);
  z += (x / y);
  printf("%.2f\n", z);
  return 1;
}
}  // namespace brainbench_2

#endif // _BRAINBENCH_2_H_
