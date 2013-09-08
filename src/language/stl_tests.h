#ifndef _STL_TESTS_H
#define _STL_TESTS_H

#include <vector>
#include <iostream>

bool _isspace(char ch) {
  return ch == ' ';
}

namespace stl_tests {
int test() {
  using namespace std;

  std::vector<int> v;
  // fill it up somehow
  v.push_back(99);
  v.push_back(1);
  v.push_back(2);
  v.push_back(99);
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v.at(i) << ' ';
  }
  endl(cout);
  cout << "v size =" << v.size() << endl;
  v.erase(std::remove(v.begin(), v.end(), 99), v.end()); // really remove all elements with value 99
  cout << "v size =" << v.size() << endl;
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v.at(i) << ' ';
  }
  endl(cout);

  std::string str("a a a a a");
  cout << str << endl;
  str.erase(std::remove_if(str.begin(), str.end(), _isspace), str.end());
  cout << str << endl;
  return 1;
}
} //  stl_tests

#endif //  _STL_TESTS_H
