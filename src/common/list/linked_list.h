/*
 * linked_list.h
 *
 *  Created on: 04 џэт. 2015 у.
 *      Author: andy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "node.h"

namespace linked_list {

template<typename T> void print_linked_list(list::Node<T>* node);

template<typename T>
void print_list(list::Node<T>* node) {
  if (!node)
    return;
  while (node) {
    std::cout<< node->data << " ";
  }
  std::endl(std::cout);
}


}  // namespace linked_list



#endif /* LINKED_LIST_H_ */
