/*
 * norm_filepath.h
 *
 *  Created on: Feb 12, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_NORM_FILEPATH_H_
#define SRC_ALGORITMS_NORM_FILEPATH_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

namespace norm_filepath {

struct normal_path {
  normal_path() {
  }

  bool valid(std::string v) {
    if (v.find("..") != std::string::npos && v.size() > 2) {
      return false;
    }
    return true;
  }

  void operator()(std::string s) {
    std::cout << "s:" << s << ", ";
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;

    istringstream iss(s);
    std::vector<std::string> vec;

    for (std::string token; getline(iss, token, '/');)
      if (token.length() >0 )
        vec.push_back(token);

//    for(auto v: vec)
//      std::cout << "["<<v << "] ";
//    std::cout << std::endl;

    std::deque<std::string> deque;
//    std::cout << "vec size="<< vec.size()<< std::endl;
    for (std::string v : vec) {
      if (!valid(v)) {
        std::cout << "incorrect path element:" << v << std::endl;
        return;
      }
      if (0 == v.compare("..")) {
//        std::cout << "found ..";
        if (deque.empty()) {
          std::cout << "incorrect path:" << s << std::endl;
          return;
        } else {
          deque.pop_back();
        }
      } else {
        deque.push_back(v);
      }
    }

    std::cout << std::endl;
//    std::cout << "deque.size=" << deque.size() << std::endl;

    if (deque.empty()) {
      std::cout << '/';
    } else {
      for (auto it = deque.begin(); it != deque.end(); ++it) {
//        if (it != deque.begin())
//          std::cout << '/';
        std::cout << *it;
      }
    }
    std::cout << std::endl;
  }

};

TEST_RESULT test() {
  __SCOPE_LOG__;
  std::string sample1 = "/a/b/c";
  std::string sample2 = "/a/b/../c";
  std::string sample3 = "/a/b/c/../";
  std::string sample4 = "/a/b/c/../../";
  std::string sample5 = "/a/b/../c../";
  std::string sample6 = "/a/b/../c../";
  std::string sample7 = "/a/b/../c/../../";
  std::string sample8 = "/a/../c/../../";

  std::vector<std::string> vec;
  vec.push_back(sample1);
  vec.push_back(sample2);
  vec.push_back(sample3);
  vec.push_back(sample4);
  vec.push_back(sample5);
  vec.push_back(sample6);
  vec.push_back(sample7);
  vec.push_back(sample8);

  std::for_each(vec.begin(), vec.end(), normal_path());

  RETURN_OK();
}
}  // namespace norm_filepath

#endif /* SRC_ALGORITMS_NORM_FILEPATH_H_ */
