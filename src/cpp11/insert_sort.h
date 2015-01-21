/*
 * insert_sort.h
 *
 *  Created on: 21 џэт. 2015 у.
 *      Author: andy
 */

#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#include <algorithm>

int test() {
  for (auto i = start; i != end; ++i)
    std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
  return 1;
}
#endif /* INSERT_SORT_H_ */
