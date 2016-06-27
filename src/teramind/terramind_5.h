/*
 * test_5.h
 *
 *  Created on: Jun 27, 2016
 *      Author: andy
 */

#ifndef SRC_TERAMIND_TERRAMIND_5_H_
#define SRC_TERAMIND_TERRAMIND_5_H_

namespace terramind_5 {

// You have a pointer to some element in a linked list (a => b => c => d => e).
// What is the fastest way to tell if there is a loop in the linked list
// (a => b => c => d => e => a)?
struct List {
  int data;
  List * next;
};

bool find_loop_in_list(List * head) {
  if (!head)
    return false;
  List *fast(head), *slow(head);
  bool has_circle = true;
  do {
    if (fast->next == NULL || fast->next->next == NULL) {
      has_circle = false;
      break;
    }

    fast = fast->next->next;
    slow = slow->next;
  } while (fast != slow);
  return has_circle;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  RETURN_OK();
}

}  // namespace terramind_5

#endif /* SRC_TERAMIND_TERRAMIND_5_H_ */
