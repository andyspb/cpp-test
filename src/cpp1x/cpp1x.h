/*
 * cpp11.h
 *
 *  Created on: 21 ���. 2015 �.
 *      Author: andy
 */

#ifndef CPP1X_H_
#define CPP1X_H_

#include <assert.h>


#include "cpp1x_constexpr_factorial.h"
#include "cpp1x_constexpr.h"
#include "cpp1x_insert_sort.h"
#include "cpp1x_move.h"
#include "cpp1x_quick_sort.h"
#include "cpp1x_thread.h"


namespace cpp1x {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  //  assert(cpp1x_thread::test());
//  assert(cpp1x_move::test());
//  assert(cpp11_insertsort::test());
//  assert(cpp11_quicksort::test());
  assert(cpp1x_constexpr::test());
//  assert(cpp1x_constexpr_factorial::test());

  RETURN_OK();
}
}

#endif /* CPP1X_H_ */
