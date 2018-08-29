#ifndef _BINDER1ST_H_
#define _BINDER1ST_H_

#include <iostream>
#include <functional>
#include <algorithm>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

namespace binder1st_ {
int test() {
  std::cout << "Test: binder1st  --->" << std::endl;
  std::binder1st<std::less<int> > IsNegative(std::less<int>(), 0);
  int numbers[] = { 10, -20, -30, 40, -50 };
  int cx;
  cx = static_cast<int>(count_if(numbers, numbers + 5, IsNegative));
  std::cout << "There are " << cx << " negative elements." << std::endl;
  std::binder1st<std::greater<int> > IsPositive(std::greater<int>(), 0);
  cx = static_cast<int>(count_if(numbers, numbers + 5, IsPositive));
  std::cout << "There are " << cx << " positive elements." << std::endl;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace binder1st_

#pragma GCC diagnostic pop

#endif // _BINDER1ST_H_
