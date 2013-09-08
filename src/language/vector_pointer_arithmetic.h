#ifndef _VECTOR_POINTER_ARITHMETIC_H_
#define _VECTOR_POINTER_ARITHMETIC_H_

#include <iostream>
#include <vector>

namespace vector_pointer_arithmetic {

struct C {
  C(): i(1), ii(2) {}  
  int i;
  int ii;
};

int test() {
  std::vector<C> vec(10, C());

  for (C *i = &vec[0] ; i != &vec[0] + vec.size(); ++i) {
    std::cout << (*i).i << " " << (*i).ii << " ";
  }
  std::endl(std::cout);

  int i = -1;

  int b = (i >> 1);

  std::cout << b << std::endl;


  return 1;
}

}  // namespace vector_pointer_arithmetic


#endif  // _VECTOR_POINTER_ARITHMETIC_H_