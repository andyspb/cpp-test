#ifndef CPLUSPLUS_H_
#define CPLUSPLUS_H_

#include <assert.h>

#include "test_13_1_print_last_k_lines.h"
#include "test_13_8_copy_node_to_structure.h"
#include "test_13_9_smart_ptr.h"


namespace cplusplus {

int test() {
//  assert(test_13_1_print_last_k_lines::test());
//  assert(test_13_9_smart_ptr::test());
  assert(test_13_8_copy_node_to_structure::test());
  return 1;
}
} // arrays_and_strings

#endif /* CPLUSPLUS_H_ */
