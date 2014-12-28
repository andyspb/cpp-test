/*
 * 2_4_partition_llist_around_a_value.h
 *
 *  Created on: 27 дек. 2014 г.
 *      Author: andy
 */

#ifndef _PARTITION_LLIST_AROUND_A_VALUE_H_
#define _PARTITION_LLIST_AROUND_A_VALUE_H_

#include <iostream>

namespace partition_llist_around_value {

struct Node {
  Node(int v) : data(v), next(0) {};
  int data;
  struct Node *next;
};

Node* partition(Node* node, int x) {
  Node * beforeStart(0);
  Node * afterStart(0);

  while (node) {
    Node* next = node->next;
    if (node->data < x) {
      /* Insert node into start of before list */
      node->next = beforeStart;
      beforeStart = node;
    } else {
      /* Insert node into front of after list */
      node->next = afterStart;
      afterStart = node;
    }
    node = next;
  }

  /* Merge before list and after list */
  if (!beforeStart) {
    return afterStart;
  }
  /* Find end of before list, and merge the lists */
  Node* head = beforeStart;
  while (beforeStart->next) {
    beforeStart = beforeStart->next;
  }
  beforeStart->next = afterStart;

  return head;

}

void printList(Node* list) {
  while (list)  {
    std::cout << list->data << " ";
    list = list->next;
  }
  std::cout << std::endl;
}


int test() {

  std::cout << "Partition linked list around value" <<std:: endl;

  Node * _node = new Node(0);
  Node * head = _node;
//  for (int i = 1; i < 10; i++) {
//    _node->next = new Node(i);
//    _node = _node->next;
//  }
//
//  printNodes(head);

  _node->next = new Node(1);
  _node = _node->next;
  _node->next = new Node(2);
  _node = _node->next;
  _node->next = new Node(4);
  _node = _node->next;
  _node->next = new Node(3);
  _node = _node->next;
  _node->next = new Node(5);
  _node = _node->next;
  _node->next = new Node(3);
  _node = _node->next;
  _node->next = new Node(4);
  _node = _node->next;
  _node->next = new Node(2);
  _node = _node->next;
  _node->next = new Node(1);
  _node = _node->next;
  _node->next = new Node(0);
  _node = _node->next;

  int part = 3;

  printList(head);

  Node* newNode = partition(head, part);

  std::cout << "part: " << part << std::endl;

  printList(newNode);


  return 1;
}

}



#endif /* _PARTITION_LLIST_AROUND_A_VALUE_H_ */
