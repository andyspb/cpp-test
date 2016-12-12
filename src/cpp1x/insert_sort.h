#ifndef CPP11_INSERT_SORT_H
#define CPP11_INSERT_SORT_H

#include <algorithm>
#include <iostream>

namespace insert_sort {

void print_vector(const std::vector<int>& v) {
  for (auto elem: v)  {
    std::cout << elem << " ";
  }
  std::cout<<std::endl;
}

int test() {

  std::vector<int> v;
  v.push_back(9);
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.push_back(7);
  v.push_back(0);
  v.push_back(10);

  print_vector(v);

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::rotate(std::upper_bound(v.begin(), it, *it), it, std::next(it));
  }
  print_vector(v);

  return 1;
}

}  // cpp11_insertsort
#endif /* CPP11_INSERT_SORT_H */
