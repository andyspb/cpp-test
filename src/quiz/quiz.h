//  quiz.h
//  author: andrey.krutogolov@gmail.com
//  date:   09.03.2013

#ifndef QUIZ_H_
#define QUIZ_H_

#include "quiz_38.h"
#include "quiz_39.h"
#include "quiz_42.h"
#include "quiz_43.h"

#include <assert.h>
#include <iostream>

namespace quiz {

int test() {
  std::cout << "Quiz tests:" << std::endl;
  assert(quiz_38::test());
  assert(quiz_39::test());
  assert(quiz_42::test());
  assert(quiz_43::test());

  return 1;
}

}  // namespace quiz_38

#endif  // QUIZ_H_
