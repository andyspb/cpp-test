/*
 * revert_all_bits.h
 *
 *  Created on: 29 окт. 2015 г.
 *      Author: andy
 */

#ifndef SRC_BITS_REVERT_ALL_BITS_H_
#define SRC_BITS_REVERT_ALL_BITS_H_

namespace revert_all_bits_in_byte {

template <typename T>
T reverse(T n)
{
    T rv = 0;
    for (size_t i = 0; i < b; ++i, n >>= 1)
        rv = (rv >> 1) | (n & 0x01);
    return rv;
}

int test() {

  return 1;
}


}  // namespace revert_all_bits_in_byte



#endif /* SRC_BITS_REVERT_ALL_BITS_H_ */
