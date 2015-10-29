// lock_free.h
// author: andrey.krutogolov@gmail.com
// date:   27.03.2013

#ifndef _LOCK_FREE_LOCK_FREE_H_
#define _LOCK_FREE_LOCK_FREE_H_

#include "lock_free_que.h"

namespace lock_free {

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  RETURN_OK();
}

}  // namespace lock_free



#endif  // _LOCK_FREE_LOCK_FREE_H_
