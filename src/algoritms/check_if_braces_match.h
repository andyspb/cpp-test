/*
 * check_if_braces_match.h
 *
 *  Created on: 24 апр. 2015 г.
 *      Author: andy
 */

#ifndef CHECK_IF_BRACES_MATCH_H_
#define CHECK_IF_BRACES_MATCH_H_

#include <string>
#include <stack>
#include <iostream>

namespace check_if_braces_match {

bool CheckBracesMatch(const std::string& str) {
  if (str.empty()) {
    return true;
  }
  const std::string opening_braces("[(");
  const std::string closing_braces("])");
  std::stack<char> braces_stack;
  std::string braces;
  braces.append(opening_braces);
  braces.append(closing_braces);
  for (const char& c : str) {
    if (braces.find(c) == std::string::npos)  // not a brace
      continue;
    if (std::find(opening_braces.begin(), opening_braces.end(), c)
        != opening_braces.end()) {
      braces_stack.push(c);
    } else if (std::find(closing_braces.begin(), closing_braces.end(), c)
        != closing_braces.end()) {
      if (braces_stack.empty())  // closing brace while no opening
        return false;

      if (opening_braces.find(braces_stack.top()) == closing_braces.find(c))
        // found a pair
        braces_stack.pop();
      else
        return false;
    }
  }
  return braces_stack.empty();
}

int test() {
  std::cout << "test braces" << std::endl;
  std::string test_str = "(b*x[0]^2) - x(sin(x))";
  bool b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "[a[1][1] - a[2])";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "([)]";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = ")))";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = ")))";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "1";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "[)(]";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "[assdferf(dfgrgtr[sdfegr[f]])]";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  test_str = "\0";
  b = CheckBracesMatch(test_str);
  std::cout << "test str:" << test_str << " b=" << b << std::endl;
  return 1;
}

}

#endif /* CHECK_IF_BRACES_MATCH_H_ */
