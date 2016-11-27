//  lambda_test1.h
//  author: andrey.krutogolov@gmail.com
//  date:   22.02.2013

#ifndef LAMBDA_TEST1_H_
#define LAMBDA_TEST1_H_

#include <iostream>
#include <functional>

namespace lambda_test1 {

auto func = []() {
  std::cout << "Hello world!\n";};

std::function<void()> make_function(int& x) {
  const auto px = &x;
  return [px] {
    std::cout << px << std::endl;};
}

TEST_RESULT test() {
  __SCOPE_LOG__;
//  auto f1 = func();

  int i = 3;
  auto f = make_function(i);
  i = 5;
  f();
  RETURN_OK();
}

}  // namespace lambda_test1

#endif  // LAMBDA_TEST1_H_
