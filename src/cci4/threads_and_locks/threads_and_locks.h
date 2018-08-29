/*
 * threads_and_locks.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */

#ifndef THREADS_AND_LOCKS_H_
#define THREADS_AND_LOCKS_H_

#include "test_18_3_singleton_with_lock.h"

namespace threads_and_locks {
int test() {
  assert(test_18_3_singleton_with_lock::test());
  return 1;
}
}  // namespace threads_and_locks

#endif /* THREADS_AND_LOCKS_H_ */
