/*
 * vector_test.h
 *
 *  Created on: May 14, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_VECTOR_TEST_H_
#define SRC_CPP1X_VECTOR_TEST_H_

#include <iostream>
#include <algorithm>
#include <vector>

namespace vector_test {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::vector<int> vec { 0, 5, -3, 11, -3, 7, 0, 2, 7, -6, 11, 0, 21, 12, -5 };

  auto print = [](int n) {
    std::cout<<n<<" is";
    if(n==0)
    std::cout<<" zero ";
    else if(n>0)
    std::cout<<" positive ";
    else
    std::cout<<" negative ";
    std::cout<<"number\n";
  };

  std::for_each(vec.begin(), vec.end(), print);
  RETURN_OK();
}
}  // namespace vector_test

#endif /* SRC_CPP1X_VECTOR_TEST_H_ */
