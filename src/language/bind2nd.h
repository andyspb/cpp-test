#ifndef _BIND2ND_H_
#define _BIND2ND_H_

#include <algorithm>
#include <iostream>
namespace bind2nd_ {
int test() {
  std::cout << "Test: bind2nd  --->" << std::endl;
  std::binder2nd<std::less<int> > IsNegative(std::less<int>(), 0);
  int numbers[] = { 10, -20, -30, 40, -50 };
  int cx;
  cx = static_cast<int>(std::count_if(numbers, numbers + 5, IsNegative));
  std::cout << "There are " << cx << " negative elements" << std::endl;
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
}  // namespace bind2nd_

#endif  // _BIND2ND_H_

