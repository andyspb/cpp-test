/*
 * transform_test.h
 *
 *  Created on: May 14, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_TRANSFORM_TEST_H_
#define SRC_CPP1X_TRANSFORM_TEST_H_

#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>

namespace transform_test {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::string s("hello");
  std::cout << s << std::endl;

  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) {return std::toupper(c);});
  std::cout << s << std::endl;

  RETURN_OK();
}

}  // namespace transform_test

#endif /* SRC_CPP1X_TRANSFORM_TEST_H_ */
