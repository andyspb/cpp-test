#ifndef _BINDER2ND_H_
#define _BINDER2ND_H_

#include <algorithm>
#include <iostream>
#include <functional>

namespace binder2nd_ {
int test() {
  std::cout << "Test: binder2nd  --->" << std::endl;
  int numbers[] = { 10, -20, -30, 40, -50, 60, -70 };
  int cx;
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  std::binder1st<std::less<int> > IsNegative(std::less<int>(), 0);
  cx = static_cast<int>(count_if(numbers, numbers + 5, IsNegative));
  std::cout << "There are " << cx << " negative elements." << std::endl;
  std::binder2nd<std::greater<int> > IsPositive(std::greater<int>(), 0);
  cx = static_cast<int>(count_if(numbers, numbers + 5, IsPositive));
  std::cout << "There are " << cx << " negative elements." << std::endl;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace binder2nd_

#endif // _BINDER1ST_H_
