#ifndef BITS_ARITHMETIC_H_
#define BITS_ARITHMETIC_H_

#include <iostream>

namespace bits_arithmetic {
int test() {
  std::cout << "Test: bits arithmetics --->" << std::endl;
  int X = 1, Y =1, Z =0;
  int output = (X & Y) | (X & Z) | (Y & Z) ;
  std::cout << "output: " << output << std::endl;
  return 1;
}
} // namespace bits_arithmetic


#endif /* BITS_ARITHMETIC_H_ */
