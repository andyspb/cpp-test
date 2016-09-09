/*
 * bits.h
 *
 *  Created on: 08 ���. 2015 �.
 *      Author: andy
 */

#ifndef BITS_H_
#define BITS_H_

#include <assert.h>

#include "add_two_bit_strings.h"
#include "binary_representation_of_number.h"
#include "bits_field.h"
#include "count_set_bits_in_an_integer.h"
#include "count_total_set bits_in_all_numbers_from_1_to_n.h"
#include "detect_if_two_integers_have_opposite_signs.h"
#include "is_div_by_9.h"
#include "is_palindrome.h"
#include "lsb_msb.h"
#include "revert_all_bits.h"
#include "swap_2_numbers_xor.h"
#include "swap_all_odd_and_even_bits.h"
#include "swap_two_nibbles_in_a_byte.h"
#include "turn_off_K_bit_in_number.h"

namespace bits {

TEST_RESULT test() {
  __SCOPE_LOG__;
//  assert(add_two_bit_strings::test());
//  assert(binary_representation_of_number::test());
///  assert(bits_field::test());
  //  assert(count_set_bits_in_an_integer::test());
//  assert(count_total_set_bits_in_all_numbers_from_1_to_n::test());
//  assert(detect_if_two_integers_have_opposite_signs::test());
//  assert(is_div_by_9::test());
//  assert(is_palindrome::test());
//  assert(lsb_msb::test());
  assert(revert_all_bits_in_byte::test());
//  assert(swap_2_numbers_xor::test());
//  assert(swap_all_odd_and_even_bits::test());
//  assert(swap_two_nibbles_in_a_byte::test());
//  assert(turn_off_K_bit_in_number::test());
  return 1;
}

}

#endif /* BITS_H_ */
