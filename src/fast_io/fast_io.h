/*
 * fast_io.h
 *
 *  Created on: Apr 24, 2017
 *      Author: andy
 */

#ifndef SRC_FAST_IO_FAST_IO_H_
#define SRC_FAST_IO_FAST_IO_H_

#include "fast_cin.h"
#include "fast_scan.h"

namespace fast_io {

TEST_RESULT test() {
  __SCOPE_LOG__;
//  assert(fast_cin::test());
  assert(fast_scan::test());
  RETURN_OK();
}

}  // namespace fast_io

#endif /* SRC_FAST_IO_FAST_IO_H_ */
