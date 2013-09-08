//  set_test.h
//  author: andrey.krutogolov@gmail.com
//  date:   27.02.2013


#ifndef SET_TEST_H_
#define SET_TEST_H_

#include <iostream>
#include <iterator>
#include <set>

namespace set_test {

int test() {
  std::set<int> s;
  s.insert(0);
  s.insert(1);
  s.insert(4);
  s.insert(3);
  s.insert(6);
  s.insert(5);

  typedef std::set<int>::iterator set_iter;

  for (set_iter it = s.begin(); it!= s.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::endl(std::cout);
  return 1;
}

}  // namespace set_test

#endif  // SET_TEST_H_
