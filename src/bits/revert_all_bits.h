/*
 * revert_all_bits.h
 *
 *  Created on: 29 ���. 2015 �.
 *      Author: andy
 */

#ifndef SRC_BITS_REVERT_ALL_BITS_H_
#define SRC_BITS_REVERT_ALL_BITS_H_

#include <string>
#include <sstream>

namespace revert_all_bits_in_byte {

const char* byte_to_binary(int x) {
  static char b[sizeof(int) * 8 + 1] = { 0 };
  int y;
  long long z;
  for (z = 1LL << (sizeof(int) * 8 - 1), y = 0; z > 0; z >>= 1, y++) {
    b[y] = (((x & z) == z) ? '1' : '0');
  }

  b[y] = 0;

  return b;
}

unsigned char reverse(unsigned char original) {
  unsigned char reversed = 0;
  for (int i = 0; i < 8; i++)
    reversed |= ((original >> i) & 0b1) << (7 - i);

  return reversed;
}
TEST_RESULT test() {
  __SCOPE_LOG__;

  unsigned char data = 8;
  unsigned char rev = reverse(data);
  LOG(INFO) << "original:" << data << ") " << " reversed:" << rev;

  RETURN_OK();
}

}  // namespace revert_all_bits_in_byte

#endif /* SRC_BITS_REVERT_ALL_BITS_H_ */
