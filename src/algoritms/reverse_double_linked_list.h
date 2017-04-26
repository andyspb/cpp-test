/*
 * reverse_double_linked_list.h
 *
 *  Created on: 26 ����. 2017 �.
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_REVERSE_DOUBLE_LINKED_LIST_H_
#define SRC_ALGORITMS_REVERSE_DOUBLE_LINKED_LIST_H_

namespace reverse_double_linked_list {
// Consider the following function that takes reference to head of a Doubly
// Linked List as parameter. Assume that a node of doubly linked list has
// previous pointer as prev and next pointer as next.

struct Node {
  Node(int v, Node* n, Node* p)
      : value(v),
        next(n),
        prev(p) {
  }
  int value;
  Node* next;
  Node* prev;
};

void print_dlist(Node* node) {
  while (node) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

void reverse_dlist(struct Node *head_ref) {
  struct Node *temp = NULL;
  struct Node *current = head_ref;

  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != NULL)
    head_ref = temp->prev;
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  Node n1(1, 0, 0);
  Node n2(2, 0, &n1);
  n1.next = &n2;
  Node n3(3, 0, &n2);
  n2.next = &n3;

  print_dlist(&n1);
  reverse_dlist(&n1);
  print_dlist(&n3);

  RETURN_OK();
}

}  // namespace reverse_double_linked_list

#endif /* SRC_ALGORITMS_REVERSE_DOUBLE_LINKED_LIST_H_ */
