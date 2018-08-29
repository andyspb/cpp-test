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
typedef std::unordered_set<int>::iterator hash_set_iterator;
typedef std::pair<hash_set_iterator, bool> value;

void print_array(const array_int8& arr) {
  std::for_each(arr.begin(), arr.end(), [](int n) {std::cout<<n<<" ";});
  std::endl(std::cout);
}

void print_hash_set(const hash_set& hs) {
  std::cout << "(";
  std::for_each(hs.begin(), hs.end(),
                [](const int v) {std::cout << v << ", ";});
  std::cout << ")";
}

bool find_in_range_in_distance(const array_int8& arr, size_t distance,
                               size_t range = 0) {

  hash_set hs;
  size_t i(0), count;
  size_t arr_size = arr.size();

  for (count = 0; count <= arr_size - distance; ++count) {
    i = count;
    size_t dist_counter = 0;
    if (i == 0) {
      std::cout << "adding to set: ";
      while (dist_counter++ < distance) {
        std::cout << arr[i] << " ";
        bool inserted = (hs.insert(arr[i])).second;
        std::cout << "(" << inserted << ") ";
        if (!inserted)
          return true;
        ++i;
      }
    } else {
      std::cout << "deleting from set: " << arr[count - 1] << std::endl;
      hs.erase(arr[count - 1]);
      std::cout << "adding to set: ";
      std::cout << arr[count + distance - 1] << " ";
      bool inserted = (hs.insert(arr[count + distance - 1])).second;
      std::cout << "(" << inserted << ") ";
      if (!inserted)
        return true;

    }
    print_hash_set(hs);
    std::endl(std::cout);
//    print_hash_set(hs);
  }

  return false;
}

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  std::cout << std::boolalpha;

  int n = 4;  // distance
  int t = 5;  // max delta

  array_int8 arr = { 1, 26, 7, 8, 99, 21, 22, 21 };
  print_array(arr);

  bool found = find_in_range_in_distance(arr, 3);

  LOG(INFO) << "found: " << found;

  RETURN_OK();
}

}  // namespace yandex

#endif /* SRC_YANDEX_YANDEX_H_ */
