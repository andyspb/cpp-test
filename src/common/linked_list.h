/*
 * linked_list.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

namespace linked_list {

template<typename T>
class SingleListNode {
  T data;
  SingleListNode *next;
};

template<typename T>
class DoubleLinkedList {
  T data;
  DoubleLinkedList * prev;
  DoubleLinkedList * next;
};

template<typename T>
SingleListNode<T>* reverse_single_linked_iter(SingleListNode<T>* node) {
  if (!node || !node->next)
    return node;
  SingleListNode<T> *t(0), *r(0);
  while(node) {
    t = node;
    node = node->next;
    t->next = r;
    r = t;
  }
  return r;
}

template<typename T>
SingleListNode<T>* reverse_single_linked_rec(SingleListNode<T>* node) {
  if (!node || !node->next)
    return node;
  SingleListNode<T>* r = reverse_single_linked_rec(node->next);
  node->next->next = node;
  node->next = 0;
  return r;
}

template<typename T>
void print_single_list(SingleListNode<T>* node) {
  if (!node)
    return;
  while (node) {
    std::cout<< node->data << " ";
  }
  std::endl(std::cout);
}
}  // namespace linked_list



#endif /* LINKED_LIST_H_ */
