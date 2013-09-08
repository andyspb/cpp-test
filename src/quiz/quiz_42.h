//  quiz_42.h
//  author: andrey.krutogolov@gmail.com
//  date:   09.03.2013

#ifndef QUIZ_42_H_
#define QUIZ_42_H_

#include <iostream>

namespace quiz_42 {

int test() {

  int sum = 0;

//  int array[3][] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
  int array[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

  for (int i = 0; i < 3; ++i) {
    for (int j = 2; j < 3; j++) {
      std::cout << array[i][j] << std::endl;
      sum += array[i][j];
    }
  }

  std::cout << sum << std::endl;

  return 1;
}

}

#endif  // QUIZ_42_H_
