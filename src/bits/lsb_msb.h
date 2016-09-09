/*
 * lsb_msb.h
 *
 *  Created on: 02 ����. 2015 �.
 *      Author: andy
 */

#ifndef LSB_MSB_H_
#define LSB_MSB_H_

namespace lsb_msb {

//  right-most bit
int LeastSignificantBit(int i) {
  int index = 0;

  while ((~i) & 1) {
    i >>= 1;
    ++index;
  }
  return 1 << index;
}

// left-most bit
int MostSignificantBit(int i) {
  int index = 0;

  while ((~i) & 1) {
    i >>= 1;
    ++index;
  }
  return 1 << index;
}

//get most significant bit;
int get_MSB_position(unsigned int x) {
  if (!x)
    return -1;
  unsigned int pos = 0, temp = 0;
  for (int i = 0x10; i > 0; i >>= 1) {
    temp = x >> i;
    if (temp) {
      x = temp;
      pos += i;
    }
  }
  return pos + x;
}

//get least significant bit position
int get_LSB_position(unsigned int x) {
  if (x == 0)
    return -1;
  int pos = 32;
  if (x & 0xffff) {
    pos -= 16;
  } else {
    x >>= 16;
  };
  if (x & 0xff) {
    pos -= 8;
  } else {
    x >>= 8;
  }
  if (x & 0xf) {
    pos -= 4;
  } else {
    x >>= 4;
  }
  if (x & 0x3) {
    pos -= 2;
  } else {
    x >>= 2;
  }
  if (x & 1) {
    pos -= 1;
  }
  return pos;
}

TEST_RESULT test() {
  __SCOPE_LOG__;
  RETURN_OK();
}

}  // lsb_msb

#endif /* LSB_MSB_H_ */
