/*
 * inserting_vector_in_sorted_order.h
 *
 *  Created on: Jul 5, 2017
 *      Author: andy
 */

#ifndef SRC_CPP1X_INSERTING_VECTOR_IN_SORTED_ORDER_H_
#define SRC_CPP1X_INSERTING_VECTOR_IN_SORTED_ORDER_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <array>

namespace inserting_vector_in_sorted_order {

void display_vector(const std::vector<int> &v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  // imagine you read unsorted contents from file or network
  // std array is used for convenience and keep example simple

  std::array<int, 6> unsorted_arr { 51, 23, 46, 32, 76, 18 };
  std::vector<int> sorted_vec;

  for (int n : unsorted_arr) {
    auto it = std::lower_bound(sorted_vec.begin(), sorted_vec.end(), n);
    if (it == sorted_vec.end() || (it != sorted_vec.end() && *it != n)) {
      sorted_vec.insert(it, n);
    }
    display_vector(sorted_vec);
    std::cout << std::endl;
  }

  RETURN_OK();
}

}  // namespace inserting_vector_in_sorted_order

#endif /* SRC_CPP1X_INSERTING_VECTOR_IN_SORTED_ORDER_H_ */
