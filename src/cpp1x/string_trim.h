/*
 * string_trim.h
 *
 *  Created on: Dec 10, 2016
 *      Author: andy
 */

#ifndef SRC_CPP1X_STRING_TRIM_H_
#define SRC_CPP1X_STRING_TRIM_H_

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

namespace string_trim {

// trim from start
std::string& left_trim(std::string &s) {
  s.erase(
      s.begin(),
      std::find_if(s.begin(), s.end(),
                   std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
std::string& right_trim(std::string &s) {
  s.erase(
      std::find_if(s.rbegin(), s.rend(),
                   std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
      s.end());
  return s;
}

// trim from both ends
std::string& trim(std::string &str) {
  return left_trim(right_trim(str));
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace string_trim

#endif /* SRC_CPP1X_STRING_TRIM_H_ */
