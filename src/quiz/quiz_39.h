//  quiz_39.h
//  author: andrey.krutogolov@gmail.com
//  date:   09.03.2013

#ifndef QUIZ_39_H_
#define QUIZ_39_H_

#include <iostream>

namespace quiz_39 {

const char* Foo() {
  return "Hello World";
}

int test() {

  const char* str = Foo();
  std::cout << str << std::endl;

  return 1;
}

}

#endif  // QUIZ_39_H_
