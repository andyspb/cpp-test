/*
 * examples.h
 *
 *  Created on: May 8, 2017
 *      Author: andy
 */

#ifndef SRC_COMMON_LIST_EXAMPLES_H_
#define SRC_COMMON_LIST_EXAMPLES_H_

#include "node.h"

template<typename T>
list::Node<T>* reverse_linked_iter(list::Node<T>* node) {
  if (!node || !node->next)
    return node;
  list::Node<T> *t(0), *r(0);
  while(node) {
    t = node;
    node = node->next;
    t->next = r;
    r = t;
  }
  return r;
}

template<typename T>
list::Node<T>* reverse_single_linked_rec(list::Node<T>* node) {
  if (!node || !node->next)
    return node;
  list::Node<T>* r = reverse_single_linked_rec(node->next);
  node->next->next = node;
  node->next = 0;
  return r;
}




#endif /* SRC_COMMON_LIST_EXAMPLES_H_ */
