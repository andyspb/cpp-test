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

  void operator()(std::string s) {
    std::cout<<"s:"<<s<<"\n";
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;
  }

};


TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::string sample1 = "/a/b/c";
  std::string sample2 = "/a/b/../c";
  std::string sample3 = "/a/b/c/../";
  std::string sample4 = "/a/b/c../../";
  std::string sample5 = "/a/b/../c../";
  std::string sample6 = "/a/b/../c../";

  std::vector<std::string> vec;
  vec.push_back(sample1);
  vec.push_back(sample2);
  vec.push_back(sample3);
  vec.push_back(sample4);
  vec.push_back(sample5);
  vec.push_back(sample6);

  std::for_each(vec.begin(), vec.end(), normal_path());


  RETURN_OK();
}
}  // namespace norm_filepath

#endif /* SRC_ALGORITMS_NORM_FILEPATH_H_ */
