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

using namespace std;

namespace quick_sort {

typedef vector<int>::iterator iterator;

void print_vector(const std::vector<int>& v) {
  for (auto elem : v) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

template<class FwdIt, class Compare = std::less<>>
void quickSort(FwdIt first, FwdIt last, Compare cmp = Compare { }) {
  auto const N = std::distance(first, last);
  if (N <= 1)
    return;
  auto const pivot = std::next(first, N / 2);
  std::nth_element(first, pivot, last, cmp);
  quickSort(first, pivot, cmp);
  quickSort(pivot, last, cmp);
}

TEST_RESULT test() {
  __SCOPE_LOG__;
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
  //quickSort<::std::vector<int>::iterator>(v.begin(), v.end());
  quickSort(v.begin(), v.end());
#endif

  print_vector(v);
  RETURN_OK();
}

}  // namespace cpp11_quicksort

#endif /* QUICK_SORT_H_ */
