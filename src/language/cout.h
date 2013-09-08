#ifndef _COUT_H_
#define _COUT_H_

#include <iostream>
namespace cout_ {

int test() {
  std::cout << "Test cout --->" << std::endl;
  std::cout << (0 == 0);
  std::endl(std::cout);
  return 1;
}
}  // namespace cout_

#endif  // _COUT_H_
