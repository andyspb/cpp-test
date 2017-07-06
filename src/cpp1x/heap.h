/*
 * heap.h
 *
 *  Created on: Jul 6, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_HEAP_H_
#define SRC_CPP1X_HEAP_H_

#include <iostream>
#include <algorithm>
#include <vector>

namespace heap_test {

TEST_RESULT test() {
  __SCOPE_LOG__;

  std::vector<int> v { 3, 1, 4, 1, 5, 9 };

  std::cout << "initially, v: ";
  for (auto i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  std::make_heap(v.begin(), v.end());

  std::cout << "after make_heap, v: ";
  for (const auto& i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  std::pop_heap(v.begin(), v.end());
  auto largest = v.back();
  v.pop_back();
  std::cout << "largest element: " << largest << '\n';

  std::cout << "after removing the largest element, v: ";
  for (auto i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  RETURN_OK();
}

}  // namespace heap_test

#endif /* SRC_CPP1X_HEAP_H_ */
