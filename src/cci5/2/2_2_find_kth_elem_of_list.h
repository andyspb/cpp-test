/*
 * 2_2_find_kth_elem_of_list.h
 *
 *  Created on: 27 дек. 2014 г.
 *      Author: andy
 */

#ifndef _FIND_KTH_ELEM_OF_LIST_H_
#define _FIND_KTH_ELEM_OF_LIST_H_

#include <iostream>

namespace find_the_kth_from_list_end {

class Node {
 public:
  Node(int v)
      : value(v),
        next(NULL) {
  }
  ;
  int value;
  Node *next;
};

void printList(Node* list) {
  while (list != NULL) {
    std::cout << list->value << " ";
    list = list->next;
  }
  std::cout << std::endl;
}

Node* nthToLast(Node* head, int k) {
  if (k <= 0)
    return NULL;

  Node* p1(head), *p2(head);
  //6  Move p2 -forward k nodes into the list.
  for (int i = 0; i < k - 1; ++i) {
    if (p2 == NULL)
      return NULL;  // Error check
    p2 = p2->next;
  }
  if (!p2)
    return
    NULL;

  /* Now, move pi and p2 at the same speed. When p2 hits the end,
   * pi will be at the right element. */
  while (p2->next) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}

int test() {
  std::cout << "Kth from end" << std::endl;
  Node * node = new Node(0);
  Node * head = node;
  for (int i = 1; i < 10; i++) {
    node->next = new Node(i);
    node = node->next;
  }
  printList(head);
  int k = 5;
  Node * kth = nthToLast(head, k);
  int value = -1;
  if (kth)
    value = kth->value;
  std::cout << k << "th from end is: " << value << std::endl;
  return 1;
}

}

#endif /* _FIND_KTH_ELEM_OF_LIST_H_ */
