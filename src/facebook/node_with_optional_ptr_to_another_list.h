/*
 * node_with_optional_ptr_to_another_list.h
 *
 *  Created on: 15 дек. 2013 г.
 *      Author: andy
 */

#ifndef NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_
#define NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_

#include <iostream>

namespace node_with_optional_ptr_to_another_list {

template<typename T>
class Node {
 public:
  Node(T v)
      : value(v),
        next(0),
        optional(0) {
  }
  T value;
  Node<T>* next;
  Node<T>* optional;
};

void printNodes(Node<int> *& node) {
  // print with one optional node
  // no common case
  Node<int>* n(node);
  Node<int>* opt(0);
  int count(0);
  bool printed = false;
  while (n) {
    if (!opt) {
      opt = n->optional;
      ++count;
    }
    std::cout << n->value;
    if (opt && !printed) {
      printed = true;
      std::cout << "(opt)";
    }
    std::cout << " ";
    n = n->next;
  }
  std::endl(std::cout);
  while (--count > 0) {
    std::cout << "  ";
  }
  while (opt) {
    std::cout << opt->value << " ";
    opt = opt->next;
  }
  std::endl(std::cout);
}

Node<int> * flattenNodes(Node<int> * head) {
  if (!head) {
    return head;
  }

  Node<int>* prev(0);
  Node<int>* result(0);

  std::queue<Node<int>*> que;
  que.push(head);

  while (!que.empty()) {
    Node<int>* temp = que.front();
    que.pop();
    if (prev) {
      prev->next = temp;
      prev->optional = 0;
    }
    if (!result) {
      result = temp;
    }
    while (temp) {
      std::cout << temp->value << "-";
      if (temp->optional) {
        que.push(temp->optional);
      }
      temp = temp->next;
    }
    prev = temp;
  }
  return result;
}

int test() {
  std::cout << "node_with_optional_ptr_to_another_list: --->\n";
  Node<int>* head = new Node<int>(1);
  head->next = new Node<int>(2);
  head->next->next = new Node<int>(3);
  head->next->next->next = new Node<int>(7);
  head->next->next->next->next = new Node<int>(8);

  head->next->next->optional = new Node<int>(4);
  head->next->next->optional->next = new Node<int>(5);
  head->next->next->optional->next->next = new Node<int>(6);

  printNodes(head);

  Node<int>* h = flattenNodes(head);
  std::endl(std::cout);

  printNodes(h);
  std::cout << "<---end test:\n";
  return 1;
}

}  // namespace node_with_optional_ptr_to_another_list

#endif /* NODE_WITH_OPTIONAL_PTR_TO_ANOTHER_LIST_H_ */
