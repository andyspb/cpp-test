/*
 * linked_list_is_palindrome.h
 *
 *  Created on: 02 ����. 2015 �.
 *      Author: andy
 */

#ifndef LINKED_LIST_IS_PALINDROME_H_
#define LINKED_LIST_IS_PALINDROME_H_

#include <stack>
#include <iostream>

namespace linked_list_is_palindrome_with_stack {

struct Node {
  Node(int d)
      : data(d),
        next(0) {
  }
  int data;
  Node* next;
};

bool isPalindrome(Node* head) {
  Node *fast(head), *slow(head);
  std::stack<int> stack;
  while (fast && fast->next) {
    stack.push(slow->data);
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast)
    slow = slow->next;
  while (slow) {
    int top = stack.top();
    if (top != slow->data)
      return false;
    stack.pop();
    slow = slow->next;
  }
  return true;
}

bool is_palindrome_with_stack(Node *head) {
  if (!head)
    return false;
  if (!head->next)
    return true;
  Node* slow = head, *fast = head;
  std::stack<int> stack;
  while (fast && fast->next) {
    stack.push(slow->data);
    fast = fast->next->next;
    slow = slow->next;
  }
  // odd elems
  if (fast)
    slow = slow->next;

  while (slow) {
    int top = stack.top();
    std::cout << top << " " << slow->data << "\n";
    if (top != slow->data) {
      return false;
    }
    stack.pop();
    slow = slow->next;
  }
  return true;
}

void print_list(Node* node) {
  while (node) {
    std::cout << node->data << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

int test() {
  std::cout << "Is linked list a palindrome\n";
  Node n1(1);
  Node n2(2);
  n1.next = &n2;
  Node n3(3);
  n2.next = &n3;
  Node n4(4);
  n3.next = &n4;
  Node n5(3);
  n4.next = &n5;
  Node n6(2);
  n5.next = &n6;
  Node n7(1);
  n6.next = &n7;
  print_list(&n1);

  bool b = is_palindrome_with_stack(&n1);
//  bool b = isPalindrome(&n1);

  std::cout << " list is palindrome:" << b << "\n";
  return 1;
}

//template<typename T>
//List<T> * reverse_iterate(List<T> * head) {
//  if (!head || !head->next)
//    return head;
//  List<T> *t(0), *r(0);
//  while (head) {
//    t = head;
//    head = head->next;
//    t->next = r;
//    r = t;
//  }
//  return r;
//}
//
//
//bool palindromeOrNot(node *head) {
//  node *tailPointer;
//  node *headLocal = head;
//  node *reverseList = reverseLinkedListIteratively(head);
//  int response = 1;
//
//  while (headLocal != NULL && reverseList != NULL) {
//    if (headLocal->id == reverseList->id) {
//      headLocal = headLocal->next;
//      reverseList = reverseList->next;
//    } else
//      return false;
//  }
//
//  if (headLocal == NULL && reverseList == NULL)
//    return fasle;
//  else
//    return true;
//}
//

}// namespace linked_list_is_palindrome

#endif /* LINKED_LIST_IS_PALINDROME_H_ */
