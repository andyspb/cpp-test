/*
 * yandex.h
 *
 *  Created on: Sep 4, 2015
 *      Author: andy
 */

#ifndef SRC_YANDEX_YANDEX_H_
#define SRC_YANDEX_YANDEX_H_

#include <array>
#include <algorithm>
#include <iostream>
#include <unordered_set>

namespace yandex {

typedef std::array<int, 8> array_int8;
typedef std::unordered_set<int> hash_set;

void print_array(const array_int8& arr) {
  std::for_each(arr.begin(), arr.end(), [](int n){std::cout<<n<<" ";});
  std::endl(std::cout);
}

bool find_same_in_distance(const array_int8& arr, int distance) {
  bool found = false;

  hash_set hs;
  int i(0), count (0);
  while(i < distance && count < arr.size()) {
    hs.insert(arr[i++]);
  }



  return found;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

  int n = 4; // distance
  int t = 5; // max delta

  array_int8 arr = {1,26,7,8,99,21,22,55};
  print_array(arr);

  bool found = find_same_in_distance(arr, 3);


  RETURN_OK();
}

}  // namespace yandex



#endif /* SRC_YANDEX_YANDEX_H_ */
