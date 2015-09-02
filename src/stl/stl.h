/*
 * stl.h
 *
 *  Created on: 10 ���. 2015 �.
 *      Author: andy
 */

#ifndef STL_H_
#define STL_H_

#include <map>
#include <string>
#include <sstream>
#include <iostream>

#include <algorithm>

namespace stl {

typedef std::map<std::string, int> str_map;
typedef std::queue<std::string> str_que;
typedef std::stack<std::string> str_stack;
typedef std::set<std::string> str_set;

void print(std::pair<const std::string, int>& p) {
  std::cout << " print " << p.first << " " << p.second << std::endl;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  str_map mymap;
  str_set myset;

  for (int i = 0; i < 20; ++i) {
    std::stringstream ss;
    ss << i;
    mymap.insert(std::pair<std::string, int>(ss.str(), i));
    myset.insert(ss.str());
  }

  std::for_each(mymap.begin(), mymap.end(), print);

  std::for_each(myset.begin(), myset.end(),
                [](std::string s) {std::cout<<s<<" ";});
  std::cout << std::endl;
  str_que myque;
  str_stack mystack;

  for (int i = 0; i < 20; ++i) {
    std::stringstream ss;
    ss << i;
    myque.push(ss.str());
    mystack.push(ss.str());
  }

  std::cout << " myque ";
  while (!myque.empty()) {
    std::string s = myque.front();
    std::cout << s << " ";
    myque.pop();
  }
  std::cout << std::endl;

  std::cout << " mystack ";
  while (!mystack.empty()) {
    std::string s = mystack.top();
    std::cout << s << " ";
    mystack.pop();
  }
  std::cout << std::endl;

  RETURN_OK();
}

}  // namespace stl

#endif /* STL_H_ */
