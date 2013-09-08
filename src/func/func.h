//  func.h
//  author: andrey.krutogolov@gmail.com
//  date:   08.03.2013

#ifndef FUNC_H_
#define FUNC_H_

#include "functors.h"

#include <assert.h>

namespace func {

int test() {
  assert(functors::test());
  return 1;
}

}  // namespace func

#endif  // FUNC_H_
