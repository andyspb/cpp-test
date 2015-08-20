/*
 * threads.h
 *
 *  Created on: 31 ��� 2015 �.
 *      Author: andy
 */

#ifndef SRC_THREAD_THREADS_H_
#define SRC_THREAD_THREADS_H_

#include "deadlock.h"
#include "futures.h"
#include "join.h"
#include "promises.h"

namespace threads {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(deadlock::test());
//  assert(futures::test());
  assert(join::test());


  RETURN_OK();
}

}

#endif /* SRC_THREAD_THREADS_H_ */
