/*
 * algoritms.h
 *
 *  Created on: May 19, 2012
 *      Author: Andy
 */

#ifndef ALGORITMS_H_
#define ALGORITMS_H_

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "array_characters_reverse.h"
#include "array_find_duplicates.h"
#include "balance_bst.h"
#include "best_path.h"
#include "big_little_endian.h"
#include "binary_search.h"
#include "blum_filter.h"
#include "breadth_first_traversal_for_a_graph.h"
#include "btree_depth.h"
#include "bubble_sort.h"
#include "bubblesort.h"
#include "byte_array_2_string.h"
#include "check_open_closed_brackets.h"
#include "circular_buffer.h"
#include "circular_que.h"
#include "common_data.h"
#include "compare_linked_list.h"
#include "count_1_in_binary.h"
#include "count_inversions_in_array_with_merge.h"
#include "count_inversions_in_array.h"
#include "dijkstra_shortest_path_algorithm.h"
#include "dinics_algorithm_maximum_flow.h"
#include "drawcircle.h"
#include "duplication.h"
#include "encode_string_google.h"
//#include "encode_string_google2.h"
#include "heapsort.h"
#include "encode_string_google.h"
#include "fibbonachi.h"
#include "fibbonachi_sum.h"
#include "find_largest_sum_in_array.h"
#include "find_minimum_length_unsorted_subarray.h"
#include "find_sum_overlapping_intervals.h"
#include "fizzbuzz.h"
#include "free_linked_list.h"
#include "google_test.h"
#include "heapsort.h"
#include "insert_into_sorted_list.h"
#include "insertsort.h"
#include "interpolation_search.h"
#include "intersection_point_of_two_linked_lists.h"
#include "is_linked_list_palindrome.h"
#include "merge_sort.h"
#include "multiply_by_7.h"
#include "my_atoi.h"
#include "radix_sort.h"
#include "reverse_linked_list.h"
#include "reverse_sentense.h"
#include "reverse_string_1.h"
#include "quicksort.h"
#include "quicksort_2linked_list.h"
#include "tree_traversal.h"
#include "is_linked_list_palindrome.h"
#include "linear_search.h"
#include "median_of_2_arr_2.h"
#include "median_of_2arrays.h"
#include "merge_overlapping_itnervals.h"
#include "merge_sort.h"
#include "minimax.h"
#include "multiply_7.h"
#include "multiply_by_7.h"
#include "my_atoi.h"
#include "norm_filepath.h"
#include "num_to_str.h"
#include "palindrom_rec.h"
#include "palindrome.h"
#include "pcm_buffer.h"
#include "permutation_of_string.h"
#include "piramid_sort.h"
#include "pow.h"
#include "simple_moving_average.h"
#include "staircase.h"
#include "reverse_string_3.h"
#include "reverse_double_linked_list.h"
#include "shell_sort.h"
#include "singleton_with_mutex.h"
#include "singleton.h"
#include "singleton_static.h"
#include "sorted_linked_list_to_balanced_bst.h"
#include "sorted_list_to_bst.h"
#include "square_root.h"
#include "string_unique_chars.h"
#include "substr_search.h"
#include "sum_1_to_N.h"
#include "sum_array.h"
#include "swap_bits.h"
#include "tree_traversal.h"
#include "tree_distance.h"
#include "turn_off_bit_in_number.h"
#include "check_if_braces_match.h"
#include "check_tree_is_bst.h"
#include "pow_x_n.h"
#include "longest_common_subseq.h"
#include "merge_sort_linked_linkedlist.h"
#include "merge_sort_linked_linkedlist.h"
#include "reverse_string_2.h"
#include "reverse_string_3.h"
#include "paradox_monti_holl.h"
#include "paradox_monti_holl_2.h"
#include "selection_sort.h"

namespace algorithms {
int test() {
  __SCOPE_LOG__;
//  assert(longest_common_subseq::test());
//  assert(binary_search::test());
//  assert(balance_bst::test());
//  assert(best_path::test());
//  assert(breadth_first_traversal_for_a_graph::test());
//  assert(btree_depth::test());
//  assert(bubblesort::test());
//  assert(byte_array_2_string::test());
//  assert(check_if_braces_match::test());
//  assert(circular_buffer::test());
//  assert(circular_que::test());
//  assert(compare_linked_lists::test());
//  assert(count_ones_in_binary::test());
//  assert(dijkstra_shortest_path_algorithm::test());
//  assert(dinics_algorithm_maximum_flow::test());
//  assert(drawcircle::test());
//  assert(duplication::test());
//  assert(encode_string_google::test());
//  assert(fibbonachi::test());
//  assert(fibbonachi_sum::test());
//  assert(find_dup_in_array::test());
//  assert(find_largest_sum_in_array::test());
//  assert(fizzbuzz::test());
  //  assert(free_linkedlist::test());
//  assert(google_test::test());
//  assert(heapsort::test());
//  assert(reverse_char_array::test());
//  assert(insert_into_sorted_slist::test());
//  assert(insertsort::test());
//  assert(interpolation_search::test());
//  assert(merge_sort::test());
//  assert(mergesort_linkedlist::test());
//  assert(minimax::test());
//  assert(my_atoi::test());
//  assert(multiply_by_7::test());
//  assert(norm_filepath::test());
//  assert(radix_sort::test());
//  assert(reverse_char_array::test());
//  assert(reverse_linkedlist::test());
//  assert(reverse_string_2::test());
//  assert(reverse_string_3::test());
//  assert(selection_sort::test());
//  assert(simple_moving_average::test());
//  assert(singleton::test());
//  assert(staircase::test());
//  assert(reverse_sentense::test());
//  assert(reverse_string_1::test());
//  assert(quicksort::test());
//  assert(qsort_2linked_list::test());
//  assert(tree_traversal::test());
//  assert(tree_distance::test());
//  assert(linked_list_is_palindrome_with_stack::test());
//  assert(pow_x_n::test());
//  assert(permutation_of_string::test());
//  assert(sum_array::test());
//  assert(pcm_buffer::test());
//  assert(palindrome::test());
//  assert(palindrom_rec::test());
  assert(reverse_double_linked_list::test());
//  assert(check_tree_is_bst::test());
//  assert(check_open_closed_brackets::test());
//  assert(paradox_monti_holl::test());
//  assert(paradox_monti_holl_2::test());
//  assert(shellsort::test());
  RETURN_OK();
}

}  // namespace algorithms

#endif /* ALGORITMS_H_ */
