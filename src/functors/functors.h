//  func.h
//  author: andrey.krutogolov@gmail.com
//  date:   08.03.2013

#ifndef FUNC_H_
#define FUNC_H_

#include <assert.h>

#include "functors_base.h"
#include "increment.h"

namespace functors {
TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(functors_base::test());
//  assert(increment::test());
  RETURN_OK();
}
}  // namespace functors

#endif  // FUNC_H_
