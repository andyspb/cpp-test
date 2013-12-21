#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "circ_que.h"
#include "binary_tree.h"
#include "node_with_optional_ptr_to_another_list.h"
#include "print_btree_levels.h"
#include "sqrt_with_precision.h"

#include <assert.h>
#include <iostream>

namespace facebook {

int test() {
  std::cout << "facebook tests --->\n";
  // assert(circ_que::test());
  // assert(binary_tree::test());
//  assert(node_with_optional_ptr_to_another_list::test());
//  assert(print_btree_levels::test());
  assert(sqrt_with_precision::test());
  std::cout << "<--- end of facebook tests\n";
  return 1;
}

}  // namespace facebook

#endif // FACEBOOK_H
