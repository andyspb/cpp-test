#ifndef _BIND1ST_H_
#define _BIND1ST_H_

#include <iostream>
#include <functional>
#include <algorithm>
#include <iostream>
namespace bind1st_ {
void param_test(...) {
}
int test() {
  std::cout << "Test: bind1st  --->" << std::endl;
  std::binder1st<std::equal_to<int> > equal_to_10(std::equal_to<int>(), 10);
  std::binder1st<std::not_equal_to<int> > not_equal_to_10(
      std::not_equal_to<int>(), 10);
  int numbers[] = { 10, 20, 30, 40, 50, 10 };
  int cx;
  cx = static_cast<int>(count_if(numbers, numbers + 6, equal_to_10));
  std::cout << "There are " << cx << " elements equal to 10.\n";
  cx = static_cast<int>(count_if(numbers, numbers + 6, not_equal_to_10));
  std::cout << "There are " << cx << " elements NOT equal to 10.\n";
  std::cout << "<--- test passed" << std::endl;
  return 1;
}
} // namespace bind1st_

#endif // #define _BIND1ST_H_
