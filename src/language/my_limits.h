#pragma once
#include <iostream>
#include <limits>

namespace limits_test {

int test(void)

{

  std::cout << "unsigned int max:\t\t"
      << std::numeric_limits<unsigned int>::max() << std::endl;
  std::cout << "int max:\t\t" << std::numeric_limits<int>::max() << std::endl;
  std::cout << "double max:\t\t" << std::numeric_limits<double>::max()
      << std::endl;
  return 0;
}

}
