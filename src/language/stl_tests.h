#ifndef _STL_TESTS_H
#define _STL_TESTS_H

#include <vector>
#include <iostream>

bool _isspace(char ch) {
  return ch == ' ';
}

namespace stl_tests {
int test() {

  std::vector<int> v;
  // fill it up somehow
  v.push_back(99);
  v.push_back(1);
  v.push_back(2);
  v.push_back(99);
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << ' ';
  }
  std::endl(std::cout);
  std::cout << "v size =" << v.size() << std::endl;
  v.erase(std::remove(v.begin(), v.end(), 99), v.end());  // really remove all elements with value 99
  std::cout << "v size =" << v.size() << std::endl;
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << ' ';
  }
  std::endl(std::cout);

  std::string str("a a a a a");
  std::cout << str << std::endl;
  str.erase(std::remove_if(str.begin(), str.end(), _isspace), str.end());
  std::cout << str << std::endl;
  return 1;
}
}  // namespace stl_tests

#endif //  _STL_TESTS_H
