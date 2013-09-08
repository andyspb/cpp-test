#ifndef _REVERSE_LLIST_1_H_
#define _REVERSE_LLIST_1_H_

#include <iostream>

namespace reverse_llist_1 {
struct _Node {
    explicit _Node(int i)
        : value(i), next(NULL) {
    }
    int value;
    _Node * next;
};

void printNodes(_Node * node) {
  while (node != NULL) {
    std::cout << node->value << " ";
    node = node->next;
  }
  std::endl(std::cout);
}

void ReverseLinkedListTest() {
  std::cout << "Reverse linked list test" <<std:: endl;
  _Node * _node = new _Node(0);
  _Node * head = _node;
  for (int i = 1; i < 10; i++) {
    _node->next = new _Node(i);
    _node = _node->next;
  }
  _node = NULL;
  printNodes(head);
  _Node * reverseList = NULL;
  _Node * tmp = NULL;
  while (head) {
    tmp = head;
    head = head->next;
    tmp->next = reverseList;
    reverseList = tmp;
  }

  printNodes(reverseList);
}
} // namespace reverse_llist_1

#endif // _REVERSE_LLIST_1_H_
