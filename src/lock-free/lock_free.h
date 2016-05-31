// lock_free.h
// author: andrey.krutogolov@gmail.com
// date:   27.03.2013

#ifndef _LOCK_FREE_LOCK_FREE_H_
#define _LOCK_FREE_LOCK_FREE_H_

#include "lock_free_queue.h"
#include "lock_free_buffer.h"
#include "lock_free_circular_que.h"
#include "lock_free_ring_buffer.h"

namespace lock_free {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;

//  assert(lock_free_queue::test());
//  assert(lock_free_buffer::test());
//  assert(lock_free_circular_que::test());
  assert(lock_free_ring_buffer::test());

  RETURN_OK();
}

}  // namespace lock_free



#endif  // _LOCK_FREE_LOCK_FREE_H_
