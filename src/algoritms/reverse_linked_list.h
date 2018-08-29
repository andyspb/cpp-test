#ifndef _REVERSE_LINKED_LIST_H_
#define _REVERSE_LINKED_LIST_H_

#include <iostream>

namespace reverse_linkedlist {

// single linked list
template<typename T = int>
struct Node {
  T val;
  Node *next;
};

//template <>
//struct Node<int> {
//    int val;
//    Node *next;
//};

template<typename T>
Node<T> * reverse_iterate(Node<T> * head) {
  if (!head || !head->next) {
    return head;
  }

  Node<T> *temp(0), *rev(0);
  while (head) {
    temp = head;
    head = head->next;
    temp->next = rev;
    rev = temp;
  }

  return rev;
}

template<typename T>
Node<T> * reverse_recursive(Node<T> *head) {
  if (!head || head->next)
    return head;

  Node<T> *rec = reverse_recursive(head->next);
  head->next->next = head;
  head->next = 0;

  return rec;
}

template<typename T>
void print_slist_int(Node<T> * head) {
  Node<T> * temp = head;
  while (temp) {
    std::cout << " " << static_cast<int>(temp->val);
    temp = temp->next;
  }
  std::endl(std::cout);
}

void fill_slist(Node<> * head, int size) {
  Node<> *temp = head;
  for (int i = 1; i < size; ++i) {
    Node<> *node = new Node<>();
    node->val = i;
    node->next = NULL;
    temp->next = node;
    temp = node;
  }
}

TEST_RESULT test() {
  __SCOPE_LOG__;

  Node<int> *list = new Node<int>();
  list->val = 0;
  list->next = NULL;

  Node<int> *temp = list;
  for (int i = 1; i < 20; ++i) {
    Node<int> *l = new Node<int>();
    l->val = i;
    l->next = NULL;
    temp->next = l;
    temp = l;
  }

  LOG(INFO) << " Print origin list";

  print_slist_int(list);

  LOG(INFO) << " Reverse iterative";
  list = reverse_iterate(list);
  print_slist_int(list);

  LOG(INFO) << " Reverse recursive";
  list = reverse_recursive(list);
  print_slist_int(list);
  RETURN_OK();
}

}  // namespace reverse_linkedlist

#endif  // _REVERSE_LINKED_LIST_H_

