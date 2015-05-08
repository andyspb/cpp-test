#ifndef CPP11_INSERT_SORT_H
#define


#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#include <algorithm>

namespace cpp11_insersort {

int test() {
  for (auto i = start; i != end; ++i)
    std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
  return 1;
}

}  // cpp11_insersort
#endif /* CPP11_INSERT_SORT_H */
