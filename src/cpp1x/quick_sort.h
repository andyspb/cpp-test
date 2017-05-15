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
#include <iterator>
#include <vector>

#include "common.h"


namespace quick_sort {

typedef std::vector<int>::iterator iterator;

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
  std::vector<int> v{9,3,2,1,7,0,10};

  print_vector_it(v);
//#ifndef __WIN64__
  //quickSort<::std::vector<int>::iterator>(v.begin(), v.end());
  quickSort(v.begin(), v.end());
//#endif

  print_vector_it(v);
  RETURN_OK();
}

}  // namespace cpp11_quicksort

#endif /* QUICK_SORT_H_ */
