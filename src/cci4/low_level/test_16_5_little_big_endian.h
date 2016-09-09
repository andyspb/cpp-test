/*
 * 16_5_test_little_endian.h
 *
 *  Created on: 13.11.2012
 *      Author: andy
 */

#ifndef TEST_16_5_LITTLE_BIG_ENDIAN_H_
#define TEST_16_5_LITTLE_BIG_ENDIAN_H_

#include <iostream>

namespace test_16_5_little_big_endian {
int TestByteOrder() {
  short int word = 0x0001;
  char *byte = (char *) &word;
  return (byte[0] ? 1 : 0);
}

int test() {
  __SCOPE_LOG__;

  LOG(INFO) << "TestByteOrder() = " << TestByteOrder() << std::endl;
  return 1;
}

}  // namespace test_16_5_little_big_endian

#endif /* TEST_16_5_LITTLE_BIG_ENDIAN_H_ */
