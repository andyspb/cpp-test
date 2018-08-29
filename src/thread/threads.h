/*
 * threads.h
 *
 *  Created on: 31 ��� 2015 �.
 *      Author: andy
 */

#ifndef SRC_THREAD_THREADS_H_
#define SRC_THREAD_THREADS_H_

#include "conditional.h"
#include "conditional_posix.h"
#include "deadlock.h"
#include "futures.h"
#include "join.h"
#include "promises.h"
#include "threads_posix.h"

namespace threads_ {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(conditional_variable::test());
//  assert(conditional_posix::test());
  assert(deadlock::test());
//  assert(futures::test());
//  assert(join::test());
//  assert(threads_posix::test());

  RETURN_OK();
}

}

#endif /* SRC_THREAD_THREADS_H_ */
