/*
 * quick_sort.h
 *
 *  Created on: 22 ���. 2015 �.
 *      Author: andy
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <algorithm>
#include <functional>
#include <vector>

namespace cpp11_quicksort {

void print_vector(const std::vector<int>& v) {
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

// fix window compile error mingw windows7
#ifndef __WIN64__
template<class Compare = std::less<std::vector<int>::iterator>>
void quickSort(::std::vector<int>::iterator first,
               ::std::vector<int>::iterator last, Compare cmp = Compare { }) {
  auto const N = std::distance(first, last);
  if (N <= 1)
    return;
  auto const pivot = ::std::next(first, N / 2);
  ::std::nth_element(first, pivot, last, cmp);
  quickSort(first, pivot, cmp);
  quickSort(pivot, last, cmp);
}

#endif

int test() {
  std::vector<int> v;
  v.emplace_back(9);
  v.emplace_back(3);
  v.emplace_back(2);
  v.emplace_back(1);
  v.emplace_back(7);
  v.emplace_back(0);
  v.emplace_back(10);

  print_vector(v);
#ifndef __WIN64__
  quickSort<::std::vector<int>::iterator>(v.begin(), v.end());
#endif

  print_vector(v);
  return 1;
}

}  // namespace cpp11_quicksort

#endif /* QUICK_SORT_H_ */
