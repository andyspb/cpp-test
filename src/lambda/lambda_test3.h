//  lambda_test3.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.02.2013

#ifndef LAMBDA_TEST3_H_
#define LAMBDA_TEST3_H_

#include <algorithm>
#include <iostream>
#include <vector>


namespace lambda_test3 {

int test() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  //...
//  std::for_each(v.begin(), v.end(), [] (int val){std::cout<<val << ' ';});
  std::endl(std::cout);
  return 1;
}

}  // namespace lambda_test3

#endif  // LAMBDA_TEST3_H_
