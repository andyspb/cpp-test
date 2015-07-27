#ifndef CPP0X_H_
#define CPP0X_H_

#include "cpp0x_move.h"
#include "cpp0x_thread.h"

#include <assert.h>
#include <iostream>

namespace cpp0x {

int test() {
  LOG(INFO)<<__PRETTY_FUNCTION__;
//  assert(cpp0x_thread::test());
  assert(cpp0x_move::test());
  return 1;
}

}  // namespace cpp0x

#endif  // CPP0X_H_
