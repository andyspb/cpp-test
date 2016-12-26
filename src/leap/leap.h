/*
 * test.h
 *
 *  Created on: 22 дек. 2016 г.
 *      Author: andy
 */

#ifndef SRC_LEAP_LEAP_H_
#define SRC_LEAP_LEAP_H_

#include "leap_1.h"
#include "leap_2.h"

namespace leap {

TEST_RESULT test() {
  __SCOPE_LOG__;
  assert(_leap_1::test());
  assert(_leap_2::test());
  RETURN_OK();
}

}  // namespace heap_test

#endif /* SRC_LEAP_LEAP_H_ */
