/*
 * 2_1_remove_duplicates_from_unsorted_linked_list.h
 *
 *  Created on: 27 дек. 2014 г.
 *      Author: andy
 */

#ifndef _REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_
#define _REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_

#include <istream>

//2.1 Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?

namespace remove_dup_from_unsorted_llist {

class Node {
 public:
  Node(int v): value(v), next(NULL) {};
  int value;
  Node *next;
};

void printList(Node* list) {
  while (list != NULL)  {
    std::cout << list->value << " ";
    list = list->next;
  }
  std::cout << std::endl;
}

void printNodes(Node * node) {
  while (node != NULL) {
    std::cout << node->value << " ";
    node = node->next;
  }
  std::endl(std::cout);
}

// with buffer
void removeDupsFromList(Node* list) {
  if (!list || !list->next)
    return;
  int arr[256] = {0};
  Node* prev = list;
  while(list->next != NULL) {
    prev = list;
    list = list->next;
    if (arr[list->value] >0) {
      prev->next = list->next;
    } else {
      arr[list->value] +=1;
    }
  }

}

// without buffer
//If we don't have a buffer, we can iterate with two pointers: current which iterates
//through the linked list, and runner which checks all subsequent nodes for duplicates.
void removeDupsFromListWithoutBuffer(Node* node) {
  if (!node)
    return;
  Node* current = node;
  while (current) {
    /* Remove all future nodes that have the same value */
    Node *runner = current;
    while (runner->next) {
      if (runner->next->value == current->value) {
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    current = current ->next;
  }
}

int test() {
  std::cout << "Reverse linked list test" <<std:: endl;

  Node * _node = new Node(0);
  Node * head = _node;
//  for (int i = 1; i < 10; i++) {
//    _node->next = new Node(i);
//    _node = _node->next;
//  }
//
//  printNodes(head);

  _node->next = new Node(2);
  _node = _node->next;
  _node->next = new Node(2);
  _node = _node->next;
  _node->next = new Node(4);
  _node = _node->next;
  _node->next = new Node(4);
  _node = _node->next;
  _node->next = new Node(3);
  _node = _node->next;
  _node->next = new Node(3);
  _node = _node->next;
  _node->next = new Node(5);
  _node = _node->next;
  _node->next = new Node(6);
  _node = _node->next;
  _node->next = new Node(6);
  _node = _node->next;
  _node->next = new Node(3);
  _node = _node->next;
//
  printList(head);
//  removeDupsFromList(head);
  removeDupsFromListWithoutBuffer(head);
  printList(head);
  return 1;
}

}  // remove_dup_from_unsorted_llist

#endif /* 2_1_REMOVE_DUPLICATES_FROM_UNSORTED_LINKED_LIST_H_ */
