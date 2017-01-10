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
#include "constexpr.h"
#include "constexpr_factorial.h"
#include "decltype.h"
#include "insert_sort.h"
#include "move.h"
#include "quick_sort.h"
#include "permutation.h"
#include "ring_buffer_locked.h"
#include "ring_buffer_lock_free.h"
#include "rvalues.h"
#include "selection_sort.h"
#include "slide.h"
#include "string_trim.h"
#include "threads.h"

namespace cpp1x {

TEST_RESULT test() {
  __SCOPE_LOG__;
//  assert(conditional_variable_::test());
//  assert(threads::test());
//  assert(move::test());
//  assert(insert_sort::test());
  assert(quick_sort::test());
//  assert(constexpr_::test());
//  assert(constexpr_factorial::test());
//  assert(decltype_::test());
//  assert(permutation::test());
//  assert(ring_buffer_locked::test());
//  assert(ring_buffer_lock_free::test());
  RETURN_OK();
}
}  // namespace cpp1x

#endif /* CPP1X_H_ */
