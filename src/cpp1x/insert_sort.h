#ifndef CPP11_INSERT_SORT_H
#define CPP11_INSERT_SORT_H

#include <algorithm>
#include <iostream>

#include "common.h"

namespace insert_sort {

int test() {

  std::vector<int> v{9,3,2,1,7,0,10};

  print_vector(v);

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::rotate(std::upper_bound(v.begin(), it, *it), it, std::next(it));
  }
  print_vector(v);

  return 1;
}

}  // cpp11_insertsort
#endif /* CPP11_INSERT_SORT_H */
