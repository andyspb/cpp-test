#ifndef _SUM_1_TO_N_H_
#define _SUM_1_TO_N_H_

#include <iostream>

namespace sum_1_to_N {
// 1+ ... + N = N*(N+1)/2
int test() {
  int n = 100;
  std::cout << "Test to calculate sum from 1 to " << n << std::endl;
  int sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum = sum + i;
  }
  std::cout << "throw loop sum is " << sum << std::endl;
  sum = n * (n + 1) / 2;
  std::cout << "throw n*(n+1)/2 sum is " << sum << std::endl;
  return 1;
}
} // namespace sum_1_to_N

#endif // _SUM_1_TO_N_H_
