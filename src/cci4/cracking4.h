#ifndef CRACKING_H_
#define CRACKING_H_

#include <iostream>

#include "arrays_and_strings/arrays_and_strings.h"
#include "cplusplus/cplusplus.h"
#include "linked_lists/linked_lists.h"
#include "low_level/low_level.h"
#include "stacks_and_queues.h/stacks_and_queues.h"
#include "threads_and_locks/threads_and_locks.h"
#include "trees_and_graphs/trees_and_graphs.h"

namespace cracking4 {
int test() {
  std::cout << "Cracking code interviews tests" << std::endl;
  assert(arrays_and_strings::test());
  assert(cplusplus::test());
  assert(linked_lists::test());
  assert(low_level::test());
  assert(threads_and_locks::test());
  assert(stacks_and_queues::test());
  assert(trees_and_graphs::test());
  std::cout << "<--- tests done" << std::endl;
  return 1;
}
}

#endif /* CRACKING_H_ */
