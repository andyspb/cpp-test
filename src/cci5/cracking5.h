/*
 * cracking5.h
 *
 *  Created on: 24 дек. 2014 г.
 *      Author: andy
 */

#ifndef CRACKING5_H_
#define CRACKING5_H_

#include "1/1_1_string_has_all_uniq_characters.h"
#include "1/1_2_reverse_string.h"
#include "1/1_3_string_permutation_of_other.h"
#include "1/1_4_replace_space_to_20.h"
#include "1/1_5_perform_string_compression.h"
#include "1/1_6_rotate_image_NxN_matrix.h"
#include "1/1_7_if_elem_in_MxN_is_0_then_row_column_0.h"
#include "1/1_8_check_if_s2_is_rotation_of_s1.h"

#include "2/2_1_remove_duplicates_from_unsorted_linked_list.h"
#include "2/2_2_find_kth_elem_of_list.h"
#include "2/2_3_del_node_in_middle_with_access_the_node_only.h"
#include "2/2_4_partition_llist_around_a_value.h"
#include "2/2_5_check_linked_list_is_palindrome.h"

#include "3/3_1_impl_three_stack_with_array.h"
#include "3/3_2_stack_with_min.h"

#include "3/3_5_impl_que_with_two_stacks.h"
#include "3/3_6_sort_stack_ascending.h"

#include "5/5_2_print_binary_of_double.h"

#include "inheritance/inheritance.h"

namespace cracking5 {
int test() {
  // 1
//  std::cout << "Cracking code interviews (5) tests 1" << std::endl;
//  assert(reverse_string::test());
//  assert(str_has_uniq_chars::test());
//  assert(string_permutation_of_other::test());
//  assert(replaceSpaces::test());
//  assert(perform_string_compression::test());
//  assert(rotate_matrix::test());
//  assert(set_matrix_col_row_zero::test());

  // 2
//  std::cout << "Cracking code interviews (5) tests 2 " << std::endl;
//  assert(remove_dup_from_unsorted_llist::test());
//  assert(find_the_kth_from_list_end::test());

  //3
//  assert(partition_llist_around_value::test());
//  assert(is_linked_list_palindrome::test());
//  assert(stack_with_min::test());
//  assert(sort_stack_ascending::test());

//  assert(inheritance_::test());

  assert(print_binary_of_double::test());

  std::cout << "<--- tests done" << std::endl;
  return 1;
}
}

#endif /* CRACKING5_H_ */
