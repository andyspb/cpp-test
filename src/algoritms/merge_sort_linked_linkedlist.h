#ifndef _MERGE_SORT_LINKED_LIST_H_
#define _MERGE_SORT_LINKED_LIST_H_

#include <iostream>

namespace mergesort_linkedlist {
// single linked list
class Node {
 public:
  int val;
  Node *next;
};

/* merge the lists.. */
Node *merge_lists(Node *h1, Node *h2) {
  // temporal
  Node *h3;

  if (!h1)
    return h2;

  if (!h2)
    return h1;

  if (h1->val < h2->val) {
    h3 = h1;
    h3->next = merge_lists(h1->next, h2);
  } else {
    h3 = h2;
    h3->next = merge_lists(h1, h2->next);
  }

  return h3;
}

Node *mergesort(Node *head) {
  Node *h1 = NULL, *h2 = NULL;

  if (!head || !head->next)
    return head;

  h1 = head;
  h2 = head->next;
  while (h2 && h2->next) {
    head = head->next;
    h2 = head->next->next;
  }
  h2 = head->next;
  head->next = 0;

  return merge_lists(mergesort(h1), mergesort(h2));
}

TEST_RESULT test() {
  std::cout << "Test: mergesort for linked list --->" << std::endl;

  struct Node* list = new Node();
  list->val = 0;
  list->next = NULL;

  Node * sl = list;
  for (int i = 1; i < 35; i++) {
    sl->next = new Node();
    sl->next->next = NULL;
    sl->next->val = 36 - i;  //( i * 345) % 100;
    sl = sl->next;
  }
  sl = list;
  while (sl) {
    std::cout << " " << sl->val;
    sl = sl->next;
  }
  std::endl(std::cout);

  list = mergesort(list);
  sl = list;
  while (sl) {
    std::cout << " " << sl->val;
    sl = sl->next;
  }
  std::endl(std::cout);
  RETURN_OK();
}
}  // namespace mergesort_linkedlist

#endif //  _MERGE_SORT_LINKED_LIST_H_
