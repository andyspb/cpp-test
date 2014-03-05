/*
 * algoritms.h
 *
 *  Created on: May 19, 2012
 *      Author: Andy
 */

#ifndef ALGORITMS_H_
#define ALGORITMS_H_

#include "array_characters_reverse.h"
#include "array_find_duplicates.h"
#include "btree_depth.h"
#include "bubblesort.h"
#include "byte_array_2_string.h"
#include "circular_que.h"
#include "compare_linked_list.h"
#include "count_1_in_binary.h"
#include "drawcircle.h"
#include "duplication.h"
#include "heapsort.h"
#include "encode_string_google.h"
#include "fibbonachi.h"
#include "find_largest_sum_in_array.h"
#include "free_linked_list.h"
#include "google_test.h"
#include "insert_into_sorted_list.h"
#include "insertsort.h"
#include "merge_sort.h"
#include "merge_sort_linked_list.h"
#include "multiply_by_7.h"
#include "my_atoi.h"
#include "reverse_linked_list.h"
#include "reverse_string_1.h"
#include "quicksort.h"
#include "tree_traversal.h"

#include <iostream>

namespace algorithms {
int test() {
  std::cout << "\t";
  std::cout << "Algorithms: -->\n";
  assert(btree_depth::test());
  assert(bubblesort::test());
  assert(byte_array_2_string::test());
  assert(circular_que::test());
  assert(compare_linked_lists::test());
  assert(count_ones_in_binary::test());
  assert(drawcircle::test());
  assert(duplication::test());
  assert(encode_string_google::test());
  assert(fibbonachi::test());
  assert(find_dup_in_array::test());
  assert(find_largest_sum_in_array::test());
  assert(free_linkedlist::test());
  assert(google_test::test());
  assert(heapsort::test());
  assert(reverse_char_array::test());
  assert(insert_into_sorted_slist::test());
  assert(insertsort::test());
  assert(merge_sort::test());
  assert(mergesort_linkedlist::test());
  assert(my_atoi::test());
  assert(multiply_by_7::test());
  assert(reverse_char_array::test());
  assert(reverse_linkedlist::test());
  assert(reverse_string_1::test());
  assert(quicksort::test());
  assert(tree_traversal::test());
  std::cout << "\t<-- algorithms end\n";
  return 1;
}

}  // namespace algorithms

#endif /* ALGORITMS_H_ */
