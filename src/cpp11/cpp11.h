/*
 * cpp11.h
 *
 *  Created on: 21 џэт. 2015 у.
 *      Author: andy
 */

#ifndef CPP11_H_
#define CPP11_H_

#include <assert.h>

#include "insert_sort.h"
#include "quick_sort.h"

namespace cpp11 {

int test() {

//  assert(cpp11_insertsort::test());
  assert(cpp11_quicksort::test());

  return 1;
}
}


#endif /* CPP11_H_ */
