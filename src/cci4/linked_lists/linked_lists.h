#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

#include <assert.h>
#include "test_2_1_remove_duplicates from_unsorted_linked)list.h"
#include "test_2_2_find_nth_to last_element_of_slist.h"
#include "test_2_3_delete_in_middle_slist.h"
#include "test_2_4_sum_linked_list.h"
#include "test_2_5_find_beginning_of_loop_in_circular_ilst.h"

namespace linked_lists {
int test() {
  assert(test_2_1::test());
  assert(test_2_2::test());
  assert(test_2_3::test());
  assert(test_2_4::test());
  assert(test_2_5::test());
  return 1;
}
}  // namespace linked_lists

#endif /* LINKED_LISTS_H_ */
