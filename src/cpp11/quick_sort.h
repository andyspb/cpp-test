/*
 * quick_sort.h
 *
 *  Created on: 22 џэт. 2015 у.
 *      Author: andy
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <functional>

namespace quicksort_cpp11 {

template<class FwdIt, class Compare = std::less<FwdIt>>
void quickSort(FwdIt first, FwdIt last, Compare cmp = Compare { }) {
  auto const N = std::distance(first, last);
  if (N <= 1)
    return;
  auto const pivot = std::next(first, N / 2);
  std::nth_element(first, pivot, last, cmp);
  quickSort(first, pivot, cmp);
  quickSort(pivot, last, cmp);
}

int test() {
  return 1;
}

}  // namespace quicksort_cpp11

#endif /* QUICK_SORT_H_ */
