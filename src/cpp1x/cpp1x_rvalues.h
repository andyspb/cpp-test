/*
 * rvalues.h
 *
 *  Created on: 01 ���� 2015 �.
 *      Author: andy
 */

#ifndef SRC_CPP1X_CPP1X_RVALUES_H_
#define SRC_CPP1X_CPP1X_RVALUES_H_

#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

namespace rvalues {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::string foo = "foo-string";
  std::string bar = "bar-string";

  std::cout << "bar:" << bar << "\n";

  std::vector<std::string> myvector;

  myvector.push_back(foo);                    // copies
  myvector.push_back(std::move(bar));         // moves

  std::cout << "myvector contains:";
  for (std::string& x : myvector)
    std::cout << ' ' << x;
  std::cout << '\n';

  std::cout << "bar:" << bar << "\n";

  RETURN_OK();
}

}

#endif /* SRC_CPP1X_CPP1X_RVALUES_H_ */
