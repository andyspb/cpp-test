//  quiz_43.h
//  author: andrey.krutogolov@gmail.com
//  date:   09.03.2013

#ifndef QUIZ_43_H_
#define QUIZ_43_H_

#include <iostream>

namespace quiz_43 {

// There can only be one function with the same signature.
// Altering the cv qualification of parameters does not change the function
// signature. Therefore the two foo functions have the same signature and
// the program is ill-formed.

//int foo(int x, int y) {
int foo(char x, int y) {
  return x + y;
}

int foo(const int x, const int y) {
  return x + y + 1;
}
int test() {
  const int x = 3;
  const int y = 2;

  std::cout << foo(x, y) << std::endl;

  return 1;
}

}

#endif  // QUIZ_43_H_
