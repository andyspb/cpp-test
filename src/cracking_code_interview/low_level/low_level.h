/*
 * low_level.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */

#ifndef LOW_LEVEL_H_
#define LOW_LEVEL_H_

#include "test_16_5_little_big_endian.h"
#include "test_16_10_two_dim_array.h"

namespace low_level {
int test() {
  assert(test_16_5_little_big_endian::test());
  assert(test_16_10_two_dim_array::test());
  return 1;
}
}// namespace low_level

#endif /* LOW_LEVEL_H_ */
