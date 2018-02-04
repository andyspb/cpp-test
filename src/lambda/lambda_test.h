/*
 * lamda_test.h
 *
 *  Created on: Nov 5, 2017
 *      Author: andy
 */

#ifndef SRC_LAMBDA_LAMBDA_TEST_H_
#define SRC_LAMBDA_LAMBDA_TEST_H_

#include <iostream>
#include <vector>

namespace lambda_test {

class MyLambda {
 public:
  void operator ()(int _x) const {
    std::cout << _x << " ";
  }
};

TEST_RESULT test() {

  std::vector<int> srcVec;
  for (int val = 0; val < 10; val++) {
    srcVec.push_back(val);
  }

  int min = 2;
  int max = 7;

  for_each(srcVec.begin(), srcVec.end(), MyLambda());
  std::cout << std::endl;

  for_each(srcVec.begin(), srcVec.end(), [](int n) {
    std::cout<<n<<" ";
  });
  std::cout << std::endl;

  std::cout << "min=" << min << " max=" << max << std::endl;

  for_each(srcVec.begin(), srcVec.end(), [min,max](int n) {
    if (n>min && n<max) {
      std::cout<<n<<" ";
    }
  });
  std::cout << std::endl;

  std::cout << "min=" << min << " max=" << max << std::endl;

  for_each(srcVec.begin(), srcVec.end(), [&] (int n) mutable {
    if (n>min && n<max) {
      std::cout<<n<<" ";
    }
    min =1;
  });
  std::cout << std::endl;
  std::cout << "min=" << min << " max=" << max << std::endl;
  RETURN_OK();
}

}  // namespace lambda_test

#endif /* SRC_LAMBDA_LAMBDA_TEST_H_ */
