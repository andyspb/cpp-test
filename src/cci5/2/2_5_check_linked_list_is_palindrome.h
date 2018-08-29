/*
 * 2_2_check_linked_list_is_singleton.h
 *
 *  Created on: 28 дек. 2014 г.
 *      Author: andy
 */

#ifndef _CHECK_LINKED_LIST_PALINDROME_H_
#define _CHECK_LINKED_LIST_PALINDROME_H_

// Implement a function to check if a linked list is a palindrome,
namespace is_linked_list_palindrome {

struct Node {
  Node(int v)
      : data(v),
        next(0) {
  }
  ;
  int data;
  struct Node *next;
};

bool isPalindrome(Node* head) {
  Node *fast(head), *slow(head);

  std::stack<int> stack;
  /* Push elements from first half of linked list onto stack. When
   * fast runner (which is moving at 2x speed) reaches the end of
   * the linked list, then we know we're at the middle */
  while (fast && fast->next) {
    stack.push(slow->data);
    slow = slow->next;
    fast = fast->next->next;
  }
  /* Has odd number of elements, so skip the middle element */
  if (fast) {
    slow = slow->next;
  }
  while (slow) {
    int top = stack.top();
    /* If values are different, then it's not a palindrome */
    if (top != slow->data) {
      return false;
    }
    stack.pop();
    slow = slow->next;
  }

  return true;
}

void printList(Node* list) {
  while (list) {
    std::cout << list->data << " ";
    list = list->next;
  }
  std::cout << std::endl;
}

int test() {
  std::cout << "Check linked list is a palindrome" << std::endl;

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

  printList(head);

  std::cout << " is palindrome: " << isPalindrome(head) << std::endl;

  return 1;
}

}  // is_linked_list_palindrome

#endif /* _CHECK_LINKED_LIST_PALINDROME_H_ */
