/*
 * cpp11.h
 *
 *  Created on: 21 ���. 2015 �.
 *      Author: andy
 */

#ifndef CPP1X_H_
#define CPP1X_H_

#include <assert.h>

#include "conditional_variable.h"
#include "cpp1x_constexpr_factorial.h"
#include "cpp1x_constexpr.h"
#include "cpp1x_insert_sort.h"
#include "cpp1x_move.h"
#include "cpp1x_rvalues.h"
#include "cpp1x_quick_sort.h"
#include "cpp1x_selection_sort.h"
#include "cpp1x_thread.h"
#include "ring_buffer_locked.h"
#include "ring_buffer_lock_free.h"

namespace cpp1x {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(conditional_variable_::test());
  //  assert(cpp1x_thread::test());
  //  assert(cpp1x_move::test());
  //  assert(cpp11_insertsort::test());
  //  assert(cpp11_quicksort::test());
  //  assert(cpp1x_constexpr::test());
  //  assert(cpp1x_constexpr_factorial::test());
  //  assert(ring_buffer_locked::test());
  assert(ring_buffer_lock_free::test());

  RETURN_OK();
}
}

#endif /* CPP1X_H_ */
