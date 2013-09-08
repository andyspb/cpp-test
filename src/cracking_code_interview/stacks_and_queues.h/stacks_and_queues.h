#ifndef STACKS_AND_QUEUES_H_
#define STACKS_AND_QUEUES_H_

#include <assert.h>

#include "test_3_5_myque_using_two_stacks.h"
#include "test_3_6_sort_stack.h"

namespace stacks_and_queues {
int test() {
  assert(test_3_5::test());
  assert(test_3_6::test());
  return 1;
}
} // stacks_and_queues

#endif /* STACKS_AND_QUEUES_H_ */
