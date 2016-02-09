//  lambda_test1.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.02.2013

#ifndef LAMBDA_TEST1_H_
#define LAMBDA_TEST1_H_

#include <iostream>

namespace lambda_test1 {

TEST_RESULT test() {
  auto func = []() {
    std::cout << "Hello world!\n";};

  func();
  RETURN_OK();
}

}  // namespace lambda_test1

#endif  // LAMBDA_TEST1_H_
