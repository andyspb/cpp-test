/*
 * cpp11.h
 *
 *  Created on: 21 ���. 2015 �.
 *      Author: andy
 */

#ifndef CPP1X_H_
#define CPP1X_H_

#include <assert.h>


#include "cpp1x_thread.h"
#include "cpp1x_insert_sort.h"
#include "cpp1x_move.h"
#include "cpp1x_quick_sort.h"

namespace cpp1x {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  //  assert(cpp1x_thread::test());
  assert(cpp1x_move::test());
  return 1;

//  assert(cpp11_insertsort::test());
//  assert(cpp11_quicksort::test());

  RETURN_OK();
}
}

#endif /* CPP1X_H_ */
